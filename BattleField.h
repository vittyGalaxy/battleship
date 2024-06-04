
/*-------------------------------------------------*/
enum Battleship:int {
    water = 0,
    one = 1,
    two = 2,
    three = 3,
    four = 4
};

enum Mode {
    verticalBottom = 0,
    horizontalLeft = 1,
    verticalUp = 2,
    horizontalRight = 3
};


/*-------------------------------------------------*/
class BattleField
{
private:
    const int n = 10;
    // struct BattleField
    // {
        
    // };
    
    /* data */

public:
    BattleField(/* args */);
    
    void init(); // tutto water
    void save();
    bool load();
    bool insertShip();
    bool insertShip(int startX, int startY, Battleship length, Mode mode);


    ~BattleField();

private:
    bool insertBattleshipVerticalUp(int startX, int startY, Battleship length);
    bool insertBattleshipHorizontalRight(int startX, int startY, Battleship length);
    bool insertBattleshipVerticalBottom(int startX, int startY, Battleship length);
    bool insertBattleshipHorizontalLeft(int startX, int startY, Battleship length);
};

/*-------------------------------------------------*/
BattleField::BattleField(/* args */)
{
}

BattleField::~BattleField()
{
}
