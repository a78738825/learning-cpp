// #include <iostream>

class Player {
  public: // Makes it so that the Variables are available OUTSIDE the class
          // through objects
    int x, y;
    int speed;

    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }
};

void some_func() {
    Player p1;
    // p1.x = 1;
    // p1.y = -1;
    // p1.speed = 2;

    p1.Move(1, -1);
}

// Remember. Everything we can do through Classes, can also be done WITHOUT
// them. They merely make the code easier to read and understand.
