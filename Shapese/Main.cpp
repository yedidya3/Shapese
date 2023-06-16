
#include <iostream>
#include <thread>

#include <array>
#include "LoadPainting.h"
#include "Objects.h"
//#include "LeakMemoryCheck.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "PerformSon.h";


using namespace experis;
using namespace std::chrono_literals;


void Write()
{
    std::unique_ptr<Group> rail = std::make_unique<Group>(Group{ 0, 24 });
     Rail(*rail);

    std::unique_ptr<Group> car = std::make_unique<Group>(Group{ 3, 3 });
    Car(*car);
    

    std::unique_ptr<Group> train = std::make_unique<Group>(Group{0,19});
    Train(*train);


    std::unique_ptr<Group> sun = std::make_unique<Group>(Group{100 , 5});
    Sun(*sun);
   // void Waggon(Group& groupy)
    std::unique_ptr<Group> img = std::make_unique<Group>(Group{0,0});
    img->Add(std::move(rail));
    img->Add(std::move(car));
    img->Add(std::move(train));
    img->Add(std::move(sun));
    
    constexpr short LENGTH_AXIS_X = 120;
	constexpr short LENGTH_AXIS_Y = 25;
    ascii::ColoredCanvas canvas{LENGTH_AXIS_X, LENGTH_AXIS_Y};
    img->Draw(canvas);
    canvas.Print(std::cout);


  
     WritePainting("file.txt" , *img);
}

void Read()
{
    std::unique_ptr<Group> rail = LoadPainting("file.txt");
    
    constexpr short LENGTH_AXIS_X = 120;
	constexpr short LENGTH_AXIS_Y = 25;
    ascii::ColoredCanvas canvas{LENGTH_AXIS_X, LENGTH_AXIS_Y};
    rail->Draw(canvas);
    canvas.Print(std::cout);
}



enum class DirectionDraw
{
    Vertical
    ,Horizontal
};

void Gate(bool a_isOpen, Group& a_group)
{
    int spaciousLeft = 1;
    int spaciousRight = 0;
    int xStart = 0;
    int ystart = 0;

    if (a_isOpen)
    {
        ++spaciousLeft;
        ++spaciousRight;
        a_group.Add<Line>(xStart , ystart, 3).SetBrush(' ').SetFg(ascii::ColoredCanvas::GREEN).SetDegrees(90);
        a_group.Add<Line>(xStart + 1, ystart, 3).SetBrush(' ').SetFg(ascii::ColoredCanvas::GREEN).SetDegrees(90);
    }
    

    a_group.Add<Line>(xStart + spaciousLeft, ystart, 3).SetBrush('<').SetFg(ascii::ColoredCanvas::GREEN).SetDegrees(90);
    a_group.Add<Line>(xStart + spaciousLeft + 1, ystart, 3).SetBrush(')').SetFg(ascii::ColoredCanvas::GREEN).SetDegrees(90);
    a_group.Add<Line>(xStart - spaciousRight, ystart, 3).SetBrush('>').SetFg(ascii::ColoredCanvas::GREEN).SetDegrees(90);
    a_group.Add<Line>(xStart - spaciousRight - 1, ystart, 3).SetBrush('(').SetFg(ascii::ColoredCanvas::GREEN).SetDegrees(90);
}


void GateHorizontal(bool a_isOpen, Group& a_group)
{
    int spaciousUp = 1;
    int spaciousDown = 0;
    int xStart = 0;
    int ystart = 0;

    if (a_isOpen)
    {
        ++spaciousUp;
        ++spaciousDown;
        a_group.Add<Line>(xStart , ystart + 1, 3).SetBrush(' ').SetFg(ascii::ColoredCanvas::GREEN);//.SetDegrees(90);
        a_group.Add<Line>(xStart , ystart, 3).SetBrush(' ').SetFg(ascii::ColoredCanvas::GREEN);//.SetDegrees(90);
    }
   


    a_group.Add<Line>(xStart , ystart + spaciousUp, 3).SetBrush('X').SetFg(ascii::ColoredCanvas::GREEN);//.SetDegrees(90);
    a_group.Add<Line>(xStart , ystart + spaciousUp + 1, 3).SetBrush('#').SetFg(ascii::ColoredCanvas::GREEN);//.SetDegrees(90);
    a_group.Add<Line>(xStart , ystart - spaciousDown, 3).SetBrush('X').SetFg(ascii::ColoredCanvas::GREEN);//.SetDegrees(90);
    a_group.Add<Line>(xStart , ystart - spaciousDown - 1, 3).SetBrush('#').SetFg(ascii::ColoredCanvas::GREEN);//.SetDegrees(90);
}

void Gate(bool a_isOpen, Group& a_group, const DirectionDraw& a_direction)
{
    if (a_direction == DirectionDraw::Horizontal)
    {
        GateHorizontal(a_isOpen, a_group);
    }
    else
    {
        Gate (a_isOpen, a_group);
    }
}




void Sword()
{
    size_t y = 0;
    size_t x = 0;

    std::unique_ptr<Group> grpPtr = std::make_unique<Group>(8,0);

    for (int i = 0 ; i < 4 ; ++i)
    {
        grpPtr->Add<Line>(x - 1, y, 0).SetBrush('<').SetFg(ascii::ColoredCanvas::GREEN);
        grpPtr->Add<Line>(x   , y , 0).SetBrush('|').SetFg(ascii::ColoredCanvas::GREEN);
        grpPtr->Add<Line>(x + 1  ,y  , 0).SetBrush(')').SetFg(ascii::ColoredCanvas::GREEN);

        grpPtr->Add<Line>(x - 4, y, 0).SetBrush('>').SetFg(ascii::ColoredCanvas::GREEN);
        grpPtr->Add<Line>(x - 5  , y , 0).SetBrush('|').SetFg(ascii::ColoredCanvas::GREEN);
        grpPtr->Add<Line>(x - 6  ,y  , 0).SetBrush('(').SetFg(ascii::ColoredCanvas::GREEN);

        y++;
    }
    --y;
    //grpPtr->Add<Line>(x + 1  , y , 0).SetBrush('o').SetFg(ascii::ColoredCanvas::GREEN);
    //grpPtr->Add<Line>(x + 2  , y++ , 0).SetBrush(')').SetFg(ascii::ColoredCanvas::GREEN);
    grpPtr->Add<Line>(x   , y , 2).SetBrush('w').SetFg(ascii::ColoredCanvas::GREEN);
    grpPtr->Add<Line>(x - 5  , y , 2).SetBrush('w').SetFg(ascii::ColoredCanvas::GREEN);
    
   
   // grpPtr->Add<Line>(x  , ++y , 0).SetBrush('|').SetFg(ascii::ColoredCanvas::GREEN);
    //grpPtr->Add<Line>(x - 1  , y , 0).SetBrush('<').SetFg(ascii::ColoredCanvas::GREEN);
    constexpr short LENGTH_AXIS_X = 120;
	constexpr short LENGTH_AXIS_Y = 25;
    ascii::ColoredCanvas canvas{LENGTH_AXIS_X, LENGTH_AXIS_Y};
    grpPtr->Draw(canvas);
    canvas.Print(std::cout);
}

void DrawBox(Group& a_group, const ascii::ColoredCanvas::Color& a_color)
{
	a_group.Add<Line>(1,0,0).SetBrush('?').SetFg(a_color);
	a_group.Add<Line>(0,1,0).SetBrush('(').SetFg(a_color);
	a_group.Add<Line>(2,1,0).SetBrush(')').SetFg(a_color);
	a_group.Add<Line>(1,1,0).SetBrush('_').SetFg(a_color);
}





int main()
{
    int x = 6;
    int y = 6;



    std::unique_ptr<Group> grpPtr = std::make_unique<Group>(3,3);
    DrawBox(*grpPtr, ascii::ColoredCanvas::BLUE);
    constexpr short LENGTH_AXIS_X = 120;
	constexpr short LENGTH_AXIS_Y = 25;
    ascii::ColoredCanvas canvas{LENGTH_AXIS_X, LENGTH_AXIS_Y};
    grpPtr->Draw(canvas);
    canvas.Print(std::cout);
    //Sword();
   // Write();
     //Read();
    
  // PerformAnimation();
    return 0;
}


void PerformAnimation()
{ 
{
    std::vector<AnimationStep*> animetionToDelete{};

	constexpr short LENGTH_AXIS_X = 120;
	constexpr short LENGTH_AXIS_Y = 25;
   
    Group backGround{0,0};
   
    Group sun{100 , 5};
    Sun(sun);

    Group rail{ 0, 24 };
    Rail(rail);

    Group train{-80,19};
    Train(train);
     
    Group car{-10,3};
    Car(car);

    
    Group tree{110, 24};
    std::list<Line*> branches = Tree(tree);

    Animation anim{};
    PerformSon k{MoveRight{}};
   // k(car);
    //anim.Add(car, 50, MoveRight{});
   // anim.Add(car, 20, MoveDown{});
    //anim.Add(car, 20, [](BaseShape& a_shape) { a_shape.MoveBy(1, 1); });

    while (anim.HasAnimation())
	{
		ascii::ColoredCanvas canvas{LENGTH_AXIS_X, LENGTH_AXIS_Y};
        sun.Draw(canvas);
		train.Draw(canvas);
        car.Draw(canvas);
        rail.Draw(canvas);
        tree.Draw(canvas);
		++anim; // This will perform MoveRight the first 50 times and then MoveDown 20 times
        canvas.Print(std::cout);
        std::this_thread::sleep_for(5ms);
    }

    
    Group cloudsRtl{0,0};
    
    for (short idx = 0 ; idx < 100 ; ++idx)
    {
        Cloud(cloudsRtl.Add<Group>(47 * idx,0));
        Cloud(cloudsRtl.Add<Group>(27 * idx * 3,10));
    }
     AnimationStep *cloutRight = new AnimationRepeat<MoveLeft>{cloudsRtl, 3, MoveLeft{}};
     animetionToDelete.push_back(cloutRight);

    Group cloudsLtr{0,0};

    for (short idx = 0 ; idx < 100 ; ++idx)
    {
        Cloud(cloudsLtr.Add<Group>(50 * (-idx),3));
    }
    AnimationStep *cloutLeft = new AnimationRepeat<MoveRight>{cloudsLtr, 3 , {}};
    animetionToDelete.push_back(cloutLeft);

    
    


    AnimationStep *carRight = new AnimationRepeat<MoveRight>{car, 1, {}};
    animetionToDelete.push_back(carRight);

    AnimationStep *carDown = new AnimationRepeat<MoveDown>{car, 1, {}}; // HINT: AnimationStep is a Base Class
	animetionToDelete.push_back(carDown);

    AnimationStep *carUp = new AnimationRepeat<MoveUp>{car, 1, {}}; // HINT: AnimationStep is a Base Class
	animetionToDelete.push_back(carDown);

	AnimationStep *trainRight = new AnimationRepeat<MoveRight>{train, 1, MoveRight{}};
    animetionToDelete.push_back(trainRight);

    //std::vector<AnimationStep*> carMove{carRight,carDown,carUp};
    for (int i = 0 ; i < tree.GetBasePoint().GetX() - car.GetBasePoint().GetX() - 65 ; ++i)
    {
        anim.Add(trainRight);
        anim.Add(trainRight);
	    //anim.Add(carMove[i % 3]);
        anim.Add(trainRight);
        anim.Add(trainRight);
         anim.Add(carRight);

         anim.Add(cloutRight);
         anim.Add(cloutLeft);
    }

   
    AnimationStep *sunLeft = new AnimationRepeat<MoveLeft>{sun, 1, MoveLeft{}};
    animetionToDelete.push_back(sunLeft);
    AnimationStep *sunDown = new AnimationRepeat<MoveDown>{sun, 1, MoveDown{}};
    animetionToDelete.push_back(sunDown);

    for (int i = 0 ; i < 9 ; ++i)
    {
	    anim.Add(carRight);
        anim.Add(carDown);
	    anim.Add(carRight);
	    anim.Add(carRight);
        anim.Add(carRight);
	    anim.Add(carRight);

        anim.Add(sunLeft);
        anim.Add(sunDown);

         anim.Add(cloutRight);
         anim.Add(cloutLeft);
    }


    for (int i = 0 ; i < 14 ; ++i)
    {
	    anim.Add(carRight);

        anim.Add(sunLeft);
        anim.Add(sunDown);

        anim.Add(cloutRight);
        anim.Add(cloutLeft);
    }
   
	while (anim.HasAnimation())
	{
		ascii::ColoredCanvas canvas{LENGTH_AXIS_X, LENGTH_AXIS_Y};
        sun.Draw(canvas);
        cloudsRtl.Draw(canvas);
        cloudsLtr.Draw(canvas);
		train.Draw(canvas);
        car.Draw(canvas);
        rail.Draw(canvas);
        tree.Draw(canvas);
		++anim; // This will perform MoveRight the first 50 times and then MoveDown 20 times
        canvas.Print(std::cout);
        std::this_thread::sleep_for(5ms);
    }

    bool isBranchDrow = false;
    while (true)
    {
		ascii::ColoredCanvas canvas{LENGTH_AXIS_X, LENGTH_AXIS_Y};
        
        car.Draw(canvas);
        tree.Draw(canvas);
        canvas.Print(std::cout);
        std::this_thread::sleep_for(100ms);

        for (Line* branch : branches)
        {
            branch->SetIsDrawn(isBranchDrow);
            isBranchDrow = !isBranchDrow;
        }
    }

    for (AnimationStep *animationStep : animetionToDelete)
    {
        delete animationStep;
    }

    
    
}
_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );
_CrtDumpMemoryLeaks();
   
}



