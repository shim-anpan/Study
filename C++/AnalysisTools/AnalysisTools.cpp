#include "AnalysisTools.h"

int main(int argc, char *argv[])
{
    // ファイルを読み込む
    ifstream file(argv[1]);
    //vector< vector<string> > values;
    vector< vector<int> > values;
    int p;
    stringstream ss;

    // 失敗時の処理
    if(file.fail()){
        cerr << "faild." << endl;
        exit(0);
    }

    string str;
    while( getline(file, str)){
        //vector<string> inner;
        vector<int> inner;
        int tmp;

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
        //inner.push_back(str);
        inner.push_back(tmp);
        values.push_back(inner);
    }
    
     
    // 単純出力
    for(unsigned int i = 0; i < values.size(); ++i){
        for(unsigned int j = 0; j < values[i].size(); ++j){
            cout << values[i][j] << ",";
        }
        cout << endl;
    }
    

    return 0;
}



