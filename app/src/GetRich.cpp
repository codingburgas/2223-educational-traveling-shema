#include <raylib.h>
#include <time.h>
#include <stdlib.h>

const char questions[15][100] =
{
    "In Marco Polo's day, Cathay was the name for China, and Cidngo was for:",
    "Thailand was once called:",
    "What is Big Ben?",
    "When was the first watch invented?",
    "Who was the first man to walk on the moon?",
    "The country with the most square shape?",
    "Which island group is only 50 miles south-east of the coast of Florida?",
    "Construction of which of these famous landmarks was completed first?",
    "Mesopotamia lies between these two rivers?",
    "Queen Anne was the daughter of which English Monarch?",
    "What is the Celsius equivalent of 77 degrees Fahrenheit?",
    "Which ancient civilization formed along the Nile River?",
    "In what year was the first iPhone released?",
    "What colour were the Pyramids of Giza originally?",
    "Which city will host the 2028 Olympic Games?"
};

const char answers[60][100] =
{
    "Japan", "Bulgaria", "Iran", "Mongolia",
    "Sesam", "Siam", "Susam", "Sumatra",
    "Clock", "Tower", "Bell", "House",
    "1700", "1500", "1400", "1893",
    "Alexander Baev", "Yuri Gagarin", "Cristiano Ronaldo", "Neil Armstrong",
    "Canada", "Russia", "Egypt", "Bulgaria",
    "Bahamas", "Turks and Caicos Islands", "US Virgin Islands", "Bermuda",
    "Empire State Building", "Eiffel Tower", "Big Ben Clock Tower", "Royal Albert Hall",
    "Tigris and Euphrates", "Nile and Indus", "Nile and Tigris", "Indus and Nile",
    "James II", "Henry VIII", "Victoria", "William I",
    "30", "25", "20", "15",
    "Mesopotamia", "Egypt", "Greece", "Rome",
    "2000", "2007", "1998", "2009",
    "Orange", "Yellow", "Brown", "White",
    "Los Angeles", "Sofia", "Beijing", "Tokyo"
};

int main()
{
    InitWindow(1920, 1080, "Get Rich");
    
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}