#include "QueryBuilder.hpp"

#include <sstream>

QueryBuilder::QueryBuilder(QueryTypes p_Type, std::string const& p_Table) : 
    m_Type(p_Type), m_Table(p_Table)
{
}

QueryBuilder::~QueryBuilder()
{
    auto l_Data = m_Values.begin();

    while (l_Data != m_Values.end())
    {
        auto& l_Vector = l_Data->second;

        for (QueryData* l_Itr : l_Vector)
            delete l_Itr;

        ++l_Data;
    }
}

void QueryBuilder::AddColumn(uint32_t p_Id, DataType p_Type, std::string p_Column, std::string p_Data)
{
    QueryData* l_Data = new QueryData(p_Type, p_Column, p_Data);

    switch (p_Type)
    {
        case DataType::None:
            m_Values[p_Id].push_back(l_Data);
            break;

        case DataType::Key:
            m_Values[p_Id].push_back(l_Data);
            break;
    }
}

std::string QueryBuilder::Generate() const
{
    std::ostringstream l_Result;
    std::ostringstream l_Values;

    switch (m_Type)
    {
        case QueryTypes::Insert:
        {
            l_Result << "INSERT INTO `" << m_Table << "` (";

            auto l_Data = m_Values.begin();

            while (l_Data != m_Values.end())
            {
                auto l_Itr = l_Data->second.begin();

                l_Values << "(";

                while (l_Itr != l_Data->second.end())
                {
                    if (l_Data == m_Values.begin())
                        l_Result << "`" << (*l_Itr)->Column << "`";

                    l_Values << "\"" << (*l_Itr)->Data << "\"";

                    if (++l_Itr != l_Data->second.end())
                    {
                        if (l_Data == m_Values.begin())
                            l_Result << ", ";

                        l_Values << ", ";
                    }
                }

                if (++l_Data != m_Values.end())
                    l_Values << "),\n";
                else
                    l_Values << ");\n";
            }

            l_Result << ") VALUES\n";

            l_Result << l_Values.str();

            break;
        }

        case QueryTypes::Replace:
        {
            l_Result << "REPLACE INTO `" << m_Table << "` (";

            auto l_Data = m_Values.begin();

            while (l_Data != m_Values.end())
            {
                auto l_Itr = l_Data->second.begin();

                l_Values << "(";

                while (l_Itr != l_Data->second.end())
                {
                    if (l_Data == m_Values.begin())
                        l_Result << "`" << (*l_Itr)->Column << "`";

                    l_Values << "\"" << (*l_Itr)->Data << "\"";

                    if (++l_Itr != l_Data->second.end())
                    {
                        if (l_Data == m_Values.begin())
                            l_Result << ", ";

                        l_Values << ", ";
                    }
                }

                if (++l_Data != m_Values.end())
                    l_Values << "),\n";
                else
                    l_Values << ");\n";
            }

            l_Result << ") VALUES\n";

            l_Result << l_Values.str();

            break;
        }

        case QueryTypes::Update:
        {
            typedef std::multimap<std::string, std::string> KeysMap;

            KeysMap l_Keys;

            auto l_Data = m_Values.begin();

            while (l_Data != m_Values.end())
            {
                l_Result << "UPDATE `" << m_Table << "` SET ";

                auto l_Itr = l_Data->second.begin();

                while (l_Itr != l_Data->second.end())
                {
                    if ((*l_Itr)->Type == DataType::Key)
                    {
                        l_Keys.insert(KeysMap::value_type((*l_Itr)->Column, (*l_Itr)->Data));

                        ++l_Itr;
                    }
                    else
                    {
                        l_Result << "`" << (*l_Itr)->Column << "` = '" << (*l_Itr)->Data << "'";

                        if (++l_Itr != l_Data->second.end())
                        {
                            l_Result << ", ";
                        }
                        else
                            l_Result << " ";
                    }
                }

                l_Result << "WHERE ";

                auto l_KeyBegin = l_Keys.begin();

                while (l_KeyBegin != l_Keys.end())
                {
                    l_Result << (*l_KeyBegin).first << " = `" << (*l_KeyBegin).second << "`";

                    if (++l_KeyBegin != l_Keys.end())
                    {
                        l_Result << ", ";
                    }
                }

                l_Keys.clear();
                
                l_Result << ";\n";

                ++l_Data;
            }

            break;
        }
    }

    return l_Result.str();
}

void QueryBuilder::Reset(QueryTypes p_Type, std::string const& p_Table)
{
    m_Type = p_Type;
    m_Table = p_Table;

    auto l_Data = m_Values.begin();

    while (l_Data != m_Values.end())
    {
        auto& l_Vector = l_Data->second;

        for (QueryData* l_Itr : l_Vector)
            delete l_Itr;

        ++l_Data;
    }

    m_Values.clear();
}

