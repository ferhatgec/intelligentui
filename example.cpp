#include <iostream>
#include "IntelligenTUI.hpp"

	
int main(int argc, char** argv) {
	if(argc < 5) {
		std::cout << "argv[1] = w, argv[2] = h, argv[3] = w, argv[4] = h.\n";
		std::cout << "tip: " << argv[0]  << " 50 30 10 10\n";
		
		return 0;
	}
	
	box_t box = itui::box_init(itui::ui_init(itui::pos_init(0, 0, atoi(argv[1]), atoi(argv[2])), itui::tag_init("my-list", 0)),
		"─", "│");
	
	box_t child = itui::box_init(itui::ui_init(itui::pos_init(0, 10, atoi(argv[3]), atoi(argv[4])), itui::tag_init("my-left-eye", 1)),
		"─", "│");
		
	box_t another_child = itui::box_init(itui::ui_init(itui::pos_init(0, 30, atoi(argv[3]), atoi(argv[4])), itui::tag_init("my-right-eye", 2)),
		"─", "│");
	
	box_t woaw_child = itui::box_init(itui::ui_init(itui::pos_init(20, 15, 30, 10), itui::tag_init("my-woaw", 3)),
		"─", "│");
	
	label_t label = itui::label_init(itui::ui_init(itui::pos_init(25, 25, 0, 0), itui::tag_init("test-label", 4)),
		"Hello, world!");
	
	itui::enable_raw_mode();
	
	itui::create_box(box, false);


	itui::create_child(box, another_child);
	itui::create_child(box, child);
	itui::create_child(box, woaw_child);
	itui::create_lchild(box, label);
		
	std::cout << "\n";
	
	/* loop for stay in raw mode */
	char c;
	
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {}
  
  	/* disable raw mode (q key pressed) */
	itui::disable_raw_mode();
	
	return 0;
}
