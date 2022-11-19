#include <raylib.h>
#include <time.h>
#include <stdlib.h>

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
int questionCounter = 0, answerCounter = 0;
Color color1 = BLACK, color2 = BLACK, color3 = BLACK, color4 = BLACK;

=======
>>>>>>> 87eb3c1 (feat(backend): add questions and answers)
=======
int questionCounter = 0, answerCounter = 0;
Color color1 = BLACK, color2 = BLACK, color3 = BLACK, color4 = BLACK;

>>>>>>> aa6ab0f (feat(backend): implement question printing)
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

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> aa6ab0f (feat(backend): implement question printing)
const char reward[16][11] ={ "    0$    ", "   100$   ", "   200$   ", "   300$   ", "   500$   ", "  1,000$  ", "  2,000$  ", "  4,000$  ", "  8,000$  ", " 16,000$  ", " 32,000$ ", " 64,000$ ", " 125,000$ ", " 250,000$ ", " 500,000$ ", "1,000,000$" };
short correctAnswers[15] = { 0, 1, 2, 1, 3, 2, 0, 2, 0, 0, 1, 1, 1, 3, 3};

void displayQuestion()
{
    DrawText(questions[questionCounter], 190, 535, 35, RAYWHITE);
    DrawText("BANK:", 315, 120, 30, ORANGE);
    DrawText(reward[questionCounter], 270, 170, 40, RAYWHITE);
    DrawText(answers[answerCounter], 190, 770, 30, color1);
    DrawText(answers[answerCounter+1], 936, 770, 30, color2);
    DrawText(answers[answerCounter+2], 190, 957, 30, color3);
    DrawText(answers[answerCounter+3], 936, 957, 30, color4);
}

<<<<<<< HEAD
int main()
{
    InitWindow(1920, 1080, "Get Rich");

    Texture2D background = LoadTexture("../assets/background.png");
    Texture2D buttonHover[4] = { LoadTexture("../assets/background-1.png"), LoadTexture("../assets/background-2.png"), LoadTexture("../assets/background-3.png"), LoadTexture("../assets/background-4.png") };
    
    Texture2D correctAnswer[4] = { LoadTexture("../assets/correct-answer-1.png"), LoadTexture("../assets/correct-answer-2.png"), LoadTexture("../assets/correct-answer-3.png"), LoadTexture("../assets/correct-answer-4.png") };
    Texture2D wrongAnswer[4] = { LoadTexture("../assets/wrong-answer-1.png"), LoadTexture("../assets/wrong-answer-2.png"), LoadTexture("../assets/wrong-answer-3.png"), LoadTexture("../assets/wrong-answer-4.png") };
    Texture2D finishScreen = LoadTexture("../assets/finish-screen.png");    

    short x = 0, y = 0;
    short choice = 4;
    int wait = 0;
    bool correct = 0;
    bool finish = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        x = GetMouseX();
        y = GetMouseY();

        if (finish)
        {
            DrawTexture(finishScreen, 0, 0, WHITE);
            DrawText("Congratulations!", 50, 250, 100, RAYWHITE);
            DrawText("You have won ", 55, 420, 80, RAYWHITE);
            DrawText(reward[questionCounter], 55, 570, 250, ORANGE);
        }
        else if (!(choice == correctAnswers[questionCounter]) && choice != 4)
        {
            DrawTexture(wrongAnswer[choice], 0, 0, WHITE);
            if (wait == 80)
            {
                wait = 0;
                finish = 1;
            }
            wait++;

        }
        else if (choice == correctAnswers[questionCounter])
        {
            DrawTexture(correctAnswer[choice], 0, 0, WHITE);

            if (wait == 80)
            {
                choice = 4;
                wait = 0;
                questionCounter++;
                answerCounter += 4;
            }
            wait++;

        }
        else if (x >= 157 && x <= 757 && y >= 695 && y <= 835)
        {
            DrawTexture(buttonHover[0], 0, 0, WHITE);
            color1 = WHITE;
            color2 = BLACK;
            color3 = BLACK;
            color4 = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 0;
            }
        }
        else if (x >= 903 && x <= 1503 && y >= 695 && y <= 835)
        {
            DrawTexture(buttonHover[1], 0, 0, WHITE);
            color1 = BLACK;
            color2 = WHITE;
            color3 = BLACK;
            color4 = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 1;
            }
        }
        else if (x >= 157 && x <= 757 && y >= 885 && y <= 1020)
        {
            DrawTexture(buttonHover[2], 0, 0, WHITE);
            color1 = BLACK;
            color2 = BLACK;
            color3 = WHITE;
            color4 = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 2;
            }
        }
        else if (x >= 903 && x <= 1503 && y >= 885 && y <= 1020)
        {
            DrawTexture(buttonHover[3], 0, 0, WHITE);
            color1 = BLACK;
            color2 = BLACK;
            color3 = BLACK;
            color4 = WHITE;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 3;
            }
        }
        else
        {
            DrawTexture(background, 0, 0, WHITE);
            color1 = BLACK;
            color2 = BLACK;
            color3 = BLACK;
            color4 = BLACK;
        }

        if (!finish)
        {
            displayQuestion();
        }
        if (questionCounter == 15)
        {
            finish = 1;
        }

        EndDrawing();
    }


    CloseWindow();
    return 0;
=======
=======
>>>>>>> 87eb3c1 (feat(backend): add questions and answers)
=======
>>>>>>> aa6ab0f (feat(backend): implement question printing)
int main()
{
    InitWindow(1920, 1080, "Get Rich");

    Texture2D background = LoadTexture("../assets/background.png");
    Texture2D buttonHover[4] = { LoadTexture("../assets/background-1.png"), LoadTexture("../assets/background-2.png"), LoadTexture("../assets/background-3.png"), LoadTexture("../assets/background-4.png") };
    
    Texture2D correctAnswer[4] = { LoadTexture("../assets/correct-answer-1.png"), LoadTexture("../assets/correct-answer-2.png"), LoadTexture("../assets/correct-answer-3.png"), LoadTexture("../assets/correct-answer-4.png") };
    Texture2D wrongAnswer[4] = { LoadTexture("../assets/wrong-answer-1.png"), LoadTexture("../assets/wrong-answer-2.png"), LoadTexture("../assets/wrong-answer-3.png"), LoadTexture("../assets/wrong-answer-4.png") };
    Texture2D finishScreen = LoadTexture("../assets/finish-screen.png");    
    short x = 0, y = 0;
    short choice = 4;
    int wait = 0;
    bool correct = 0;

    SetTargetFPS(60);

<<<<<<< HEAD
>>>>>>> 967dc07 (feat(backend): add neccessary libraries)
=======
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        x = GetMouseX();
        y = GetMouseY();

        if (!(choice == correctAnswers[questionCounter]) && choice != 4)
        {
            DrawTexture(wrongAnswer[choice], 0, 0, WHITE);
            if (wait == 80)
            {
                wait = 0;
                finish = 1;
            }
            wait++;

        }
        else if (choice == correctAnswers[questionCounter])
        {
            DrawTexture(correctAnswer[choice], 0, 0, WHITE);
            
            if (wait == 80)
            {
                choice = 4;
                wait = 0;
                questionCounter++;
                answerCounter += 4;
            }
            wait++;

        }
        else if (x >= 157 && x <= 757 && y >= 695 && y <= 835)
        {
            DrawTexture(buttonHover[0], 0, 0, WHITE);
            color1 = WHITE;
            color2 = BLACK;
            color3 = BLACK;
            color4 = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 0;
            }
        }
        else if (x >= 903 && x <= 1503 && y >= 695 && y <= 835)
        {
            DrawTexture(buttonHover[1], 0, 0, WHITE);
            color1 = BLACK;
            color2 = WHITE;
            color3 = BLACK;
            color4 = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 1;
            }
        }
        else if (x >= 157 && x <= 757 && y >= 885 && y <= 1020)
        {
            DrawTexture(buttonHover[2], 0, 0, WHITE);
            color1 = BLACK;
            color2 = BLACK;
            color3 = WHITE;
            color4 = BLACK;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 2;
            }
        }
        else if (x >= 903 && x <= 1503 && y >= 885 && y <= 1020)
        {
            DrawTexture(buttonHover[3], 0, 0, WHITE);
            color1 = BLACK;
            color2 = BLACK;
            color3 = BLACK;
            color4 = WHITE;

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                choice = 3;
            }
        }
        else
        {
            DrawTexture(background, 0, 0, WHITE);
            color1 = BLACK;
            color2 = BLACK;
            color3 = BLACK;
            color4 = BLACK;
        }

        EndDrawing();
    }


    CloseWindow();
    return 0;
>>>>>>> 87eb3c1 (feat(backend): add questions and answers)
}