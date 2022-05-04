#ifndef H_PLAYER
#define H_PLAYER

#include <string>

using namespace std;

class Player {

    public:
        Player();
        Player(string name, int color);

        int getColor() const;
        string getName() const;

    private:
        int color;
        string name;
};

#endif // H_PLAYER
