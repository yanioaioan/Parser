#include <iostream>

using namespace std;

#include <QFile>
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QDebug>
#include <typeinfo>

int main()
{
    QString fileName="main.cpp";
    QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QList <QString> fileTokens;

       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          QRegExp rx("[ ]");// match a comma or a space
          QStringList list = line.split(rx, QString::SkipEmptyParts);

          //qDebug() << list;

          for(int i = 0; i < list.size(); i++)
          {
              //qDebug() << typeid(list.at(i)).name() ;

              if (typeid(list.at(i)) ==typeid(QString))
                fileTokens.append(list.at(i)/*.toInt()*/);
          }

//          qDebug() << "Name:" << qPrintable(name);
//          //    foreach(int num, nums)
//          //    {
//          //        qDebug() << "num:" << num;
//          //    }
//          for(int i = 0; i < nums.size(); i++)
//          {
//              qDebug() << qPrintable("num" + QString::number(i+1) + ":") << nums.at(i);
//              int t=nums.at(i);
//          }
       }
       qDebug() << fileTokens ;

       inputFile.close();
    }

    return 0;
}



//taken from http://cs.dvc.edu/HowTo_Cparse.html


//#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using std::cout;
//using std::endl;

//#include <fstream>
//using std::ifstream;

//#include <cstring>

//const int MAX_CHARS_PER_LINE = 512;
//const int MAX_TOKENS_PER_LINE = 20;
//const char* const DELIMITER = " ";

//int main()
//{
//  // create a file-reading object
//  ifstream fin;
//  fin.open("main.cpp"); // open a file
//  if (!fin.good())
//    return 1; // exit if file not found

//  // read each line of the file
//  while (!fin.eof())
//  {
//    // read an entire line into memory
//    char buf[MAX_CHARS_PER_LINE];
//    fin.getline(buf, MAX_CHARS_PER_LINE);

//    // parse the line into blank-delimited tokens
//    int n = 0; // a for-loop index

//    // array to store memory addresses of the tokens in buf
//    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

//    // parse the line
//    token[0] = strtok(buf, DELIMITER); // first token
//    if (token[0]) // zero if line is blank
//    {
//      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
//      {
//        token[n] = strtok(0, DELIMITER); // subsequent tokens
//        if (!token[n]) break; // no more tokens
//      }
//    }

//    // process (print) the tokens
//    for (int i = 0; i < n; i++) // n = #of tokens
//      cout << "Token[" << i << "] = " << token[i] << endl;
//    cout << endl;
//  }
//}
