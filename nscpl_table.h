#pragma once
#include <string>
#include <unordered_map>

class nscpl_table {
public:
    std::unordered_map<std::string, float> m_floatMap;
    std::unordered_map<std::string, std::string> m_stringMap;
    std::unordered_map<std::string, nscpl_table> m_tableMap;

    std::unordered_map<std::string, float*> m_floatMap_ptr;
    std::unordered_map<std::string, std::string*> m_stringMap_ptr;
    std::unordered_map<std::string, nscpl_table*> m_tableMap_ptr;

    nscpl_table(){}

    //check
    bool haveFloat( std::string key){
        if(m_floatMap.find(key) != m_floatMap.end() || m_floatMap_ptr.find(key) != m_floatMap_ptr.end()){return true;}else{return false;}
    }
    bool haveString( std::string key){
        if(m_stringMap.find(key) != m_stringMap.end() || m_stringMap_ptr.find(key) != m_stringMap_ptr.end()){return true;}else{return false;}
    }
    bool haveTable( std::string key){
        if(m_tableMap.find(key) != m_tableMap.end() || m_tableMap_ptr.find(key) != m_tableMap_ptr.end()){return true;}else{return false;}
    }

    //float
    void setFloat( std::string key, float value) {
        m_floatMap[key] = value;
    }
    void setFloat( std::string key, float* value) {
        m_floatMap_ptr[key] = value;
    }
    float getFloat( std::string key) {
        if(m_floatMap.find(key) != m_floatMap.end()){
            return m_floatMap[key];
        }else if(m_floatMap_ptr.find(key) != m_floatMap_ptr.end()){
            return *m_floatMap_ptr[key];
        }else{
            return 0;
        }
    }

    //string
    void setString( std::string key,  std::string value) {
        m_stringMap[key] = value;
    }
    void setString( std::string key, std::string* value) {
        m_stringMap_ptr[key] = value;
    }
    std::string getString( std::string key) {
        if(m_stringMap.find(key) != m_stringMap.end()){
            return m_stringMap[key];
        }else if(m_stringMap_ptr.find(key) != m_stringMap_ptr.end()){
            return *m_stringMap_ptr[key];
        }else{
            return "";
        }
    }

    //table
    void setTable( std::string key, nscpl_table& table) {
        m_tableMap[key] = table;
    }
    void setString(std::string key, nscpl_table* value) {
        m_tableMap_ptr[key] = value;
    }
    nscpl_table getTable(std::string key) {
        if(m_tableMap.find(key) != m_tableMap.end()){
            return m_tableMap[key];
        }else if(m_tableMap_ptr.find(key) != m_tableMap_ptr.end()){
            return *m_tableMap_ptr[key];
        }else{
            return nscpl_table();
        }
    }


    
};