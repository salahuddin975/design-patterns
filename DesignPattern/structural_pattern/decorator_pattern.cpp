/*
----------------- Decorator Design Pattern | Structural Patterns ---------------------

Decorator Design Pattern can be used to solve these problems,
- To add or remove responsibilities to an object dynamically at run-time.
- A flexible alternative to subclassing for extending functionality should be provided.

*/


#include <iostream>


class VisualComponent
{
public:
	virtual void draw() = 0;
};

class TextViewer : public VisualComponent
{
public:
	void draw(){
		std::cout << "Text viewer." << std::endl;
	}
};

class ImageViewer : public VisualComponent
{
public:
	void draw(){
		std::cout << "Image viewer." << std::endl;
	}
};

class Decorator : public VisualComponent
{
protected:
	VisualComponent *visual_component;

public:
	Decorator(VisualComponent *vc){
		visual_component = vc;
	}

	void draw(){
		visual_component->draw();
	}
};

class ScrollDecorator : public Decorator
{
public:
	ScrollDecorator(VisualComponent *vc) : Decorator(vc) { }
	
	void draw(){
		Decorator::draw();
		drawScroll();
	}

	void drawScroll(){
		std::cout << "Add scroll bar." << std::endl;
	}
};

class BorderDecorator : public Decorator
{
public:
	BorderDecorator(VisualComponent *vc) : Decorator(vc) { }

	void draw(){
		Decorator::draw();
		drawBorder();
	}

	void drawBorder() {
		std::cout << "Add border." << std::endl;
	}
};

void decorator_pattern()
{
	std::cout << "\n------- Only text viewer --------" << std::endl;
	VisualComponent *text_viewer = new TextViewer();
	text_viewer->draw();

	std::cout << "\n------- Text viewer with scroll --------" << std::endl;
	VisualComponent *text_viewer_with_scroll = new ScrollDecorator(text_viewer);
	text_viewer_with_scroll->draw();

	std::cout << "\n------- Text viewer with scroll and border --------" << std::endl;
	VisualComponent *text_viewer_with_border = new BorderDecorator(text_viewer_with_scroll);
	text_viewer_with_border->draw();

	std::cout << "\n------- Only Image viewer --------" << std::endl;
	VisualComponent *image_viewer = new ImageViewer();
	image_viewer->draw();

	std::cout << "\n------- Image viewer with border --------" << std::endl;
	VisualComponent *image_viewer_with_border = new BorderDecorator(image_viewer);
	image_viewer_with_border->draw();
}
