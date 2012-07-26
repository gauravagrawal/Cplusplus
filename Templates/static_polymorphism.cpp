/**
 *   C++ practice examples. Example of Static and Dynamic Polymorphism
 *   Copyright (C) 2012 Gaurav Agrawal
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 **/

#include <iostream>

class Shape { 
    public :
	virtual void draw() const = 0 ; 
}; 

class Circle : public Shape { 
    public :
	virtual void draw() const { 
	    std::cout<<"Circle"<<std::endl; 
	}
}; 

class Line : public Shape { 
    public: 
	virtual void draw() const { 
	    std::cout<<"Line"<<std::endl; 
	}
}; 

class SomeRandomClass { 
    public:
	void draw() const { 
	    std::cout<<"Some random class"<<std::endl;
	}
}; 

// static polymorphic function
// This method would accept any type T which contains method "draw" in it
template<typename T> 
    void myStaticDraw(T const& obj) { 
	obj.draw();
    }

void myDynamicDraw(Shape const& obj) { 
    obj.draw();
}

int main(int argc, char **argv) { 

    // static polymorphism
    Circle circle;
    myStaticDraw(circle);

    Line line;
    myStaticDraw(line);

    SomeRandomClass foo;
    myStaticDraw(foo);

    // dynamic polymorphism
    myDynamicDraw(circle);
    myDynamicDraw(line);

    // compile time error in dynamic polymorphism
    // myDynamicDraw(foo); 

    return 0;
}
