#pragma once

#include <memory>
#include <map>
#include <deque>

enum class QueryTypes : int
{
    Insert,
    Replace,
    Update,
};

enum class DataType : int
{
    None,
    Key,
};

struct QueryData
{
    DataType Type;

    std::string Column;
    std::string Data;

    QueryData(DataType p_Type, std::string const& p_Column, std::string const& p_Data) : Type(p_Type), Column(p_Column), Data(p_Data) { }
};

typedef std::map<uint32_t, std::deque<std::unique_ptr<QueryData>>> ValuesContainer;

class QueryBuilder
{
    public:
        QueryBuilder(QueryTypes p_Type, std::string const& p_Table);
        void AddColumn(uint32_t p_Id, DataType p_Type, std::string p_Column, std::string p_Data);
        std::string Generate() const;
        void Reset(QueryTypes p_Type, std::string const& p_Table);

    private:
        QueryTypes m_Type;
        std::string m_Table;
        ValuesContainer m_Values;
};