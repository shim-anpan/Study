#include "AnalysisTools.h"
#include <map>

// Dataクラス
// 
// Common Data
// grade, class, name に関しては元々用意
// 
// Non Common Data
// 科目は ファイル読み込みまで分からないので、std::map で管理.

class Data {
    public:
        Data(){};
        ~Data(){};

    public:
        unsigned int m_grade;
        unsigned int m_class;
        unsigned int m_name;
        std::map<std::string, unsigned int> m_sub_list;

    public:
        void SetGrade( unsigned int gra ){ m_grade = gra; };
        void SetClass( unsigned int cla ){ m_class = cla; };
        void SetName( unsigned int name ){ m_name = name;};
};

// DataManager クラス
// Data 全体を扱う為のクラス
// シングルトンクラスを意識しているがちゃんと実装していない・・・

class DataManager {
    public:
        DataManager(){};
        ~DataManager(){};
        
        bool Initialize( Data *rows );
        void Finalize(){};

    public:
        unsigned int m_num_rows;
        unsigned int m_num_columns;
        Data *m_Data; 

    public:
        // Setter
        void SetNumRows( unsigned int num_rows) { m_num_rows = num_rows;};
        void SetNumColumns( unsigned int num_columns) { m_num_columns = num_columns;};

        // Getter
        void PrintData();



        // 指定番目の列を全て出力する関数
        void PrintColumns( unsigned int column );
        // 指定した名前の列を全て出力する関数
        void PrintColumns( string column);
        // 指定して名前の列の和を返す関数
        unsigned int SumColumns( string column);
        
        // TODO: 各種データ操作関数の追加
        // and so on 
};


int main(int argc, char *argv[])
{
    // ファイルを読み込む
    ifstream file(argv[1]);
    vector< vector<unsigned int> > values;
    int p;
    stringstream ss;

    // 失敗時の処理
    if(file.fail()){
        cerr << "faild." << endl;
        exit(0);
    }

    string str;
    // 1行の index データを取得
    // 科目名の配列作成
    vector<string> sublist;
   
    // 1行目を取得 
    getline(file, str);
    // カンマ毎に文字列を取得
    while( (p = str.find(",")) != str.npos ) {
        sublist.push_back(str.substr(0,p));
        str = str.substr(p+1);
    }
    sublist.push_back(str.substr(0,p));


    // 2行目移行の数値データを取得
    while( getline(file, str)){
        vector<unsigned int> inner;
        unsigned int tmp;

        while( (p = str.find(",")) != str.npos ) {
            ss << str.substr(0,p);
            ss >> tmp;
            inner.push_back(tmp);
            str = str.substr(p+1);
            ss.str(""); // バッファをクリアする。
            ss.clear(stringstream::goodbit);       

        }
        ss << str;
        ss >> tmp;
        ss.str(""); // バッファをクリアする。
        ss.clear(stringstream::goodbit);       
        inner.push_back(tmp);
        values.push_back(inner);
    }
    
    // Data クラスの配列を用意
    Data *rows = new Data[values.size()];
    for (unsigned int i = 0 ; i < values.size(); ++i){
        // Data クラス共通の 学年・クラス・名前を取得
        rows[i].SetGrade( values[i][0] );
        rows[i].SetClass( values[i][1] );
        rows[i].SetName( values[i][2] );
        // 科目のみ map に挿入
        for (unsigned int k = 3; k < sublist.size(); k++){
            rows[i].m_sub_list[sublist[k].c_str()] = values[i][k];
        }
    }

    // DataManager を初期化
    DataManager *p_DataManager = new DataManager();
    p_DataManager->Initialize( rows );
    p_DataManager->SetNumRows( values.size() );
    p_DataManager->SetNumColumns( values[0].size() );

    // Data 操作実行
    p_DataManager->PrintData();

    /*
    // 単純出力
    for(unsigned int i = 0; i < values.size(); ++i){
        for(unsigned int j = 0; j < values[i].size(); ++j){
            cout << values[i][j] << ",";
        }
        cout << endl;
    }
    */

    //  DataManager 終了処理
    p_DataManager->Finalize();

    // rows の delete 処理
    delete[] rows;
    return 0;
}

bool DataManager::Initialize( Data * rows )
{
    m_Data = rows;
    //m_num_columns = 3 + rows[0].m_sub_list.size();
    //m_num_rows = sizeof(rows) / sizeof( Data );
    return true;
}

void DataManager::PrintData()
{
    printf("num of row == %d \n", m_num_rows);
    printf("num of columns == %d \n", m_num_columns);
}

void DataManager::PrintColumns( string column )
{
    
}

