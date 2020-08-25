#include "appengine.h"
#include <string>

AppEngine::AppEngine()
    {
        std::srand(std::time(0));
        labs = new Labirynt();
        wallsVec = new MWalls(labs->GetMaze());
        robot = new Robot(8,16,15*31,15*31);
        grobot = new GRobot(robot);
        map = new GMap(wallsVec,grobot);
        core = new RobotCore();

        QGraphicsScene *scena = map->GetScene() ;

        button1 = new QPushButton();
        button1->setGeometry(30*2,17*30,100,50);
        button1->setText("Start search");
        QGraphicsProxyWidget *proxy = scena->addWidget(button1);
        button2 = new QPushButton();
        button2->setGeometry(30*11,17*30,100,50);
        button2->setText("Fastest");
        button2->setEnabled(0);
        proxy = scena->addWidget(button2);

        timer1 = new QLabel();
        timer1->setText(QString::number(searchtime));
        timer1->setGeometry(30*2,16*30+10,100,20);
        timer1->setAlignment(Qt::AlignRight);
        timer1->setStyleSheet("background-color:white;");
        proxy = scena->addWidget(timer1);

        timer2 = new QLabel();
        timer2->setText(QString::number(searchtime));
        timer2->setGeometry(30*11,16*30+10,100,20);
        timer2->setAlignment(Qt::AlignRight);
        timer2->setStyleSheet("background-color:white;");
        proxy = scena->addWidget(timer2);



        QGraphicsView * view = new QGraphicsView(scena);
        QWidget::setWindowTitle("Micromouse");
        //view->scale(1.5,1.5);
        button1->clicked();
        view->show();
        QTimer *timer = new QTimer;
        connect(button1,SIGNAL(released()),this,SLOT (button1Search()));
        connect(button2,SIGNAL(released()),this,SLOT (button2Fast()));
        connect(timer,SIGNAL(timeout()),this,SLOT(step()));
        timer->start(30);

    }

void AppEngine::step()
    {

        if(core->getFinishedSearch()){

                button2->setEnabled(1);
            }
        else
            {
                searchtime = searchTimer.elapsed()/1000;
                if(searchTimer.elapsed()>360*1000) searchtime=0;
                if(searchtime%60<10)timer1->setText("Czas szukania: " +QString::number(searchtime/60)+":0"+QString::number(searchtime%60));
                else
                timer1->setText("Czas szukania: "+QString::number(searchtime/60)+":"+QString::number(searchtime%60));
            }
        if(core->GetStop()==0)
            {
        fasttime = fastTimer.elapsed()/1000;
        if(fastTimer.elapsed()>360*1000) fasttime=0;
        if(fasttime%60<10)timer2->setText("Czas przejścia: "+QString::number(fasttime/60)+":0"+QString::number(fasttime%60));
        else
        timer2->setText("Czas przejścia: "+QString::number(fasttime/60)+":"+QString::number(fasttime%60));
            }

        core->Search(robot,wallsVec);
        grobot->move();


    }

void AppEngine::button1Search()
    {
        searchTimer.start();
        searchtime=0;
        core->setSearchMarker();
        button1->setEnabled(0);

    }

void AppEngine::button2Fast()
    {
        fastTimer.start();
        fastTimer.restart();
        fasttime=0;
        resetRobotPos();
        core->setFastMarker();
        core->setStop();
    }

void AppEngine::resetRobotPos()
    {
        robot->startPos();
    }
