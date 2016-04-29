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

