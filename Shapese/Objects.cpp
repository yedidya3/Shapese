#include "Objects.h"
namespace experis
{
	

void Stream(Group& groupy)
{
    size_t place = 0;
    short high = 0;

    groupy.Add<Line>(--place  , high + 1 , 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::WHITE).SetBrush('o');
    --place;
     groupy.Add<Line>(--place  , high , 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::WHITE).SetBrush('o');
     groupy.Add<Line>(--place , high , 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::WHITE).SetBrush(' ');

     --high;
    for (size_t idx = 0 ; idx < 20 ; ++idx)
    {
        groupy.Add<Line>(--place  , high , 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::WHITE).SetBrush('O');
        groupy.Add<Line>(--place , high , 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::WHITE).SetBrush(' ');
    }

    for (size_t idx = 0 ; idx < 4 ; ++idx)
    {
        groupy.Add<Line>(--place  , high , 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::WHITE).SetBrush('.');
        groupy.Add<Line>(--place , high , 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::WHITE).SetBrush(' ');
    }
}

void Waggon(Group& groupy)
{
  short length = 8;
  short high = 3;
  groupy.Add<Rectangle>({0,0},high, length).SetBg(Color::RED).SetFg(Color::MAGENTA).SetBrush(')');
  groupy.Add<Line>(0, high+1, 1).SetBg(Color::TERMINAL_COLOR).SetFg(Color::TERMINAL_COLOR).SetBrush('0');
  groupy.Add<Line>(length - 1, high + 1, 1).SetBg(Color::TERMINAL_COLOR).SetFg(Color::TERMINAL_COLOR).SetBrush('0');
  groupy.Add<Line>(length  , high , 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::TERMINAL_COLOR).SetBrush('=');

}


void Locomotive(Group& groupy)
{
  short length = 8;
  short high = 3;
  groupy.Add<Rectangle>({0,-1},short(high + 1), short(length / 2)).SetBg(Color::RED).SetFg(Color::BLACK).SetBrush('*');
  groupy.Add<Rectangle>({short(length / 2),1},short(high -1), length ).SetBg(Color::RED).SetFg(Color::BLACK).SetBrush('*');
  groupy.Add<Line>(1, high+1, 1).SetBg(Color::TERMINAL_COLOR).SetFg(Color::TERMINAL_COLOR).SetBrush('0');
  groupy.Add<Line>(length + 2 , high + 1, 1).SetBg(Color::TERMINAL_COLOR).SetFg(Color::TERMINAL_COLOR).SetBrush('0');
  groupy.Add<Line>(length  , 0 , 0).SetBg(Color::RED).SetFg(Color::TERMINAL_COLOR).SetBrush('|');

  Stream(groupy.Add<Group>(length+1, -2));
}

void Train(Group& groupy)
{
    short startX = 0;
    short startY = 0;
    for (size_t idx = 0 ; idx < 10 ; ++idx)
    {
        Waggon(groupy.Add<Group>(startX, startY));
        startX += 10;
    }
    Locomotive(groupy.Add<Group>(startX, startY));
}

void Rail(Group& a_group)
{
    size_t idx = 0;
    for (int i = 0 ; i < 300 ; i++)
    {
        Line& first1 = a_group.Add<Line>(++idx, 0, 2);
        ++idx;
        first1.SetBg(Color::BLACK);
        first1.SetFg(Color::WHITE);
        first1.SetBrush('-');
        Line& first2 = a_group.Add<Line>(++idx, 0, 1);
        first2.SetBg(Color::BLACK);
        first2.SetFg(Color::WHITE);
        first2.SetBrush('+');
    }

}

void Cloud(Group& a_group)
{
    char bursh = '\244';
    a_group.Add<Line>(1, 0, 9).SetBrush(bursh).SetBg(Color::TERMINAL_COLOR).SetFg(Color::BLUE);
    a_group.Add<Line>(-3, 1, 14).SetBrush(bursh).SetBg(Color::TERMINAL_COLOR).SetFg(Color::BLUE);
    a_group.Add<Line>(-1, 2, 14).SetBrush(bursh).SetBg(Color::TERMINAL_COLOR).SetFg(Color::BLUE);
    a_group.Add<Line>(1, 3, 11).SetBrush(bursh).SetBg(Color::TERMINAL_COLOR).SetFg(Color::BLUE);
    a_group.Add<Line>(0, 4, 10).SetBrush(bursh).SetBg(Color::TERMINAL_COLOR).SetFg(Color::BLUE);
}

void Sun(Group& a_group)
{
    for (size_t idx = 0 ; idx < 5 ; ++idx)
    {
        a_group.Add<Circle>(0,0, idx).SetBrush('@').SetBg(Color::TERMINAL_COLOR).SetFg(Color::YELLOW);
    }
}


void Car(Group& groupy)
{
  short length = 8;
  short high = 3;
  groupy.Add<Rectangle>({0,0},high, length).SetBg(Color::CYAN).SetFg(Color::BLUE).SetBrush(' ');
  groupy.Add<Line>(-2, high -1 , length + 5).SetBg(Color::CYAN).SetFg(Color::BLUE).SetBrush(' ');
  groupy.Add<Line>(-2, high, length + 5).SetBg(Color::CYAN).SetFg(Color::BLUE).SetBrush(' ');
  groupy.Add<Line>(-1, high+1, 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::TERMINAL_COLOR).SetBrush('0');
  groupy.Add<Line>(length , high + 1, 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::TERMINAL_COLOR).SetBrush('0');
  groupy.Add<Line>(-4  , high , 0).SetBg(Color::TERMINAL_COLOR).SetFg(Color::TERMINAL_COLOR).SetBrush('=');
  groupy.Add<Line>(-3  , 2 , 0).SetBg(Color::RED).SetFg(Color::TERMINAL_COLOR).SetBrush(' ');
  groupy.Add<Line>(10  , 2 , 0).SetBg(Color::YELLOW).SetFg(Color::TERMINAL_COLOR).SetBrush(' ');

}


std::list<Line*> Tree(Group& groupy)
{
    short highTop = 10;
      for (int i = -2;  i < 2; i++)
      {
        Line& breed = groupy.Add<Line>(i,0,highTop);//.SetDegrees(90).SetBg(Color::MAGENTA).SetFg(Color::CYAN).SetBrush(' ');
        breed.SetDegrees(-90);
        breed.SetBg(Color::MAGENTA).SetFg(Color::CYAN).SetBrush(' ');
      }


    std::list<Line*> branches;
    double degree = -220;
    for (int i = 0 ; i < 27 ; i++)
    {
        Line* branch = &groupy.Add<Line>(0, -highTop, highTop);//.SetDegrees(90).SetBg(Color::MAGENTA).SetFg(Color::CYAN).SetBrush(' ');
        branch->SetDegrees(degree);
        branch->SetBg(Color::GREEN).SetFg(Color::CYAN).SetBrush(' ');
        branches.push_back(branch);
        degree += 10;
    }
    //return branches;
    return branches;
}

} //experis

