/*
Authors: Kaylee Joyce - 0383068, Rhy Jaunzarins - 0404377

Class which holds colours for the gameplay output.
*/

#ifndef GAMECOLOURS_H
#define GAMECOLOURS_H

class GameColours {
	public:
		static constexpr const char* RESET = "\033[0m";
		static constexpr const char* RED = "\033[31m";
		static constexpr const char* GREEN = "\033[32m";
		static constexpr const char* YELLOW = "\033[33m";
		static constexpr const char* BLUE = "\033[34m";
		static constexpr const char* MAGENTA = "\033[35m";
		static constexpr const char* GREY = "\033[2m";
};
#endif
