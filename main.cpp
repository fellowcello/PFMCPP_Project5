/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */
#include <iostream>

/*
 copied UDT 1:
 */

struct Mp3Player
{
    Mp3Player();

    ~Mp3Player() 
    {
    std::cout << "Mp3Player being destructed!" << std::endl;
    }

    int numberOfButtons;
    std::string onOffSwitchColor { "white" };
    float displayScreenWidth;
    float beltClipDepth;
    int numberOfCardSlots;

    void loadFile(std::string filePath); 
    void playFile(); 
    void displayInfo(); 
    int findFiles();
};

Mp3Player::Mp3Player() :
numberOfButtons(5),
displayScreenWidth(1.0f),
beltClipDepth(1.0f),
numberOfCardSlots(1)
{
    std::cout << "Mp3Player being constructed!" << std::endl;
}

void Mp3Player::loadFile(std::string filePath)
{
    std::string newPath { "d:/" + filePath };
    std::cout << "Mp3Player::loadFile()" << newPath << std::endl;
}

void Mp3Player::playFile()
{
    std::cout << "Mp3Player::playFile() numberOfButtons:" << numberOfButtons << " beltClipDepth: " << beltClipDepth << std::endl;
}

void Mp3Player::displayInfo()
{
    
}

int Mp3Player::findFiles()
{
    int count = 0;
    for(int i = 0; i < 5; ++i)
    {
        std::cout << "file count: " << i << std::endl;
        count = i;
    }
    return count;
}







/*
 copied UDT 2:
 */

struct CdDrive
{
    CdDrive();
    ~CdDrive();

    int maxSpeed;
    float discDiameter;
    int numberOfTrays;
    std::string color { "black" };
    int numberOfFormatsSupported = 3;

    void playCd(); 
    void playDVD(); 
    void writeCdr(); 
    int findSpeed();

    struct CD
    {
        ~CD() { std::cout << "CD being destructed!" << std::endl; }
        int maxSpeed = 100;
        float outerDiameter = 5.0f;
        float innerDiameter = 0.5f;
        std::string color { "black" };
        std::string title { "Dark Side Of The Moon" };

        void getScratched(); 
        void storeData(); 
        void goObsolete(); 
    };
};

CdDrive::CdDrive() :
maxSpeed(100),
discDiameter(5.0f),
numberOfTrays(1)
{
    std::cout << "CdDrive being constructed!" << std::endl;
}

CdDrive::~CdDrive()
{
    std::cout << "CdDrive being destructed!" << std::endl;
}

void CdDrive::playCd()
{
    std::cout << "CdDrive::playCd() " << color << std::endl;
}

void CdDrive::playDVD()
{
    std::cout << "CdDrive::playDVD() maxSpeed:" << maxSpeed << " discDiameter: " << discDiameter << std::endl;
}

void CdDrive::writeCdr()
{
    
}

void CdDrive::CD::getScratched()
{
    
}

void CdDrive::CD::storeData()
{
    
}

void CdDrive::CD::goObsolete()
{
    
}

int CdDrive::findSpeed()
{
    int speed = 0;
    for(int i = 97; i < maxSpeed; ++i)
    {
        speed = i;
    }
    return speed;
}






/*
 copied UDT 3:
 */

struct Keyboard
{
    Keyboard();

    ~Keyboard()
    {
    std::cout << "Keyboard being destructed!" << std::endl;
    }

    int numberOfKeys;
    int numberOfFunctionKeys;
    std::string caseColor { "black" };
    std::string buttonColor { "gray" };
    float width = 16.0f;

    void outputButtonPress(int buttonCode); 
    void displayNumLock(); 
    void displayCapsLock(); 
    int buttonPressTime();
};

Keyboard::Keyboard() :
numberOfKeys(100),
numberOfFunctionKeys(12)
{
    std::cout << "Keyboard being constructed!" << std::endl;
}

void Keyboard::outputButtonPress(int buttonCode)
{
    ++buttonCode;
    std::cout << "Keyboard::outputButtonPress() " << buttonCode << std::endl;
}

void Keyboard::displayNumLock()
{
    std::cout << "Keyboard::displayNumLock() numberOfKeys:" << numberOfKeys << " numberOfFunctionKeys: " << numberOfFunctionKeys << std::endl;
}

void Keyboard::displayCapsLock()
{

}

int Keyboard::buttonPressTime()
{
    int time = 0;
    for(int i = 0;i < 100; ++i)
    {
        time = i;
    }
    return time;
}


/*
 new UDT 4:
 with 2 member functions
 */

struct StuffOnMyDesk
{
    StuffOnMyDesk();
    ~StuffOnMyDesk();

    Mp3Player mp3Player;
    Keyboard keyboard;

    int countThings();
    void cleanDesk();
};

int StuffOnMyDesk::countThings()
{
    return mp3Player.numberOfCardSlots + mp3Player.numberOfButtons + keyboard.numberOfFunctionKeys + keyboard.numberOfKeys;
}

void StuffOnMyDesk::cleanDesk()
{
    mp3Player.onOffSwitchColor = "shiny white";
    keyboard.caseColor = "shiny black";
}


/*
 new UDT 5:
 with 2 member functions
 */

struct ThingsToBuy
{
    ThingsToBuy();
    ~ThingsToBuy();

    CdDrive cdDrive;
    Keyboard keyboard;

    int findCdDrivePrice();
    int findKeyboardPrice();
};

ThingsToBuy::ThingsToBuy()
{
    
}

ThingsToBuy::~ThingsToBuy()
{
    
}
    
int ThingsToBuy::findCdDrivePrice()
{
    if (cdDrive.maxSpeed > 50)
    {
        return 100;
    }
    return 75;
}

int ThingsToBuy::findKeyboardPrice()
{
    if (keyboard.numberOfKeys < 50)
    {
        return 25;
    }
    return 50;
}


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
