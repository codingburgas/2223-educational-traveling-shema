#include <raylib.h>
#include <algorithm>
#include <vector>

int main()
{
    InitWindow(1920, 1080, "Captcha Solver");
    SetTargetFPS(60);
	
	std::vector<char*> givenWords;

    givenWords.push_back("HELLo");
    givenWords.push_back("wORLD");
    givenWords.push_back("VSCPI");
    givenWords.push_back("BINGO");
    givenWords.push_back("words");
    givenWords.push_back("mails");
    givenWords.push_back("SharP");
    givenWords.push_back("seize");
    givenWords.push_back("LOREM");
    givenWords.push_back("IPSUM");

    std::random_shuffle(givenWords.begin(), givenWords.end());

    CloseWindow();
    return 0;
}