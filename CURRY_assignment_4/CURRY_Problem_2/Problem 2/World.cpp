#include "World.h"

int World::randomLocation(int start, int end) const
{
    return rand() % (end - start + 1) + start;
}

World::World()
{
    srand(time(NULL)); //seed to randomize each run
    tStepCnt = 0; // initialize counter for time steps 

    //assigns all elements with nullptr initially. 
    for (int x = 0; x < 20; x++)
        for (int y = 0; y < 20; y++)
            world[x][y] = nullptr;
}

void World::startSim()
{
    int x, y; //coordinates for world assignment
    int doodleBugCnt = 0; //tracks doodlebugs in world
    int antCnt = 0; //tracks ants in world

    //generates 5 doodle bugs at sim start
    while (doodleBugCnt < 5)
    {
        x = randomLocation(0, 20 - 1);
        y = randomLocation(0, 20 - 1);
        if (world[x][y] != nullptr) //if space is occupied regenerate
            continue;
        world[x][y] = new Doodlebug(x, y); //doodle on the heap
        doodleBugCnt++;
    }

    //generates 100 ants at sim start
    while (antCnt < 100)
    {
        x = randomLocation(0, 20 - 1);
        y = randomLocation(0, 20 - 1);
        if (world[x][y] != nullptr) //if space is occupied regenerate
            continue;
        world[x][y] = new Ant(x, y); //ant on the heap
        antCnt++;
    }
}


void World::timeStep()
{
    tStepCnt++;

    //moves doodlebugs for new time step
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++)
        {
            if (world[x][y] == nullptr)
                continue;
            if (world[x][y]->getType() == 1) // 1 is doodle
                world[x][y]->move();
        }
    }
    //moves ants for new time step
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++)
        {
            if (world[x][y] == nullptr)
                continue;
            if (world[x][y]->getType() == 2) // 2 is ant
                world[x][y]->move();
        }
    }

    //checks breeding conditons for each organism
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++)
        {
            if (world[x][y] == nullptr)
                continue;
            world[x][y]->breed();
        }
    }

    //checks starving conditions for doodlebugs
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++)
        {
            if (world[x][y] == nullptr)
                continue;
            if (world[x][y]->starve())
            {
                delete world[x][y];
                world[x][y] = nullptr;
            }
        }
    }
}

void World::printWorld() const
{
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++) {
            if (world[x][y] == nullptr)
                cout << ' '; //empty spaces for null
            else if (world[x][y]->getType() == 2)
                cout << 'o';
            else  //if not null or ant, must be doodle!
                cout << 'X';
        }
        cout << endl;
    }
}

