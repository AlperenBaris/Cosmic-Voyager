#include <iostream>
#include "../inc/Printer.h"


/*This section contains the visuals required for the game, the display of the remaining features and the functions that print the game result.*/

void Printer::PrintWelcomeMessage() {
    std::cout << "              _______   _______ .___________.__   __.  ______.___   ___ .___________.  _____ \n"
                 "            //  _____| |   ____||           |  \\ |  | |   ____\\  \\ /  / |           |/ \\    \\ \n"
                 "            |  |  __   |  |__   `---|  |----|   \\|  | |  |__   \\  V  /  `---|  |----|  |  |  | \n"
                 "            |  | |_ |  |   __|      |  |    |  . `  | |   __|   >   <       |  |    |  |  |  | \n"
                 "            |  |__| |  |  |____     |  |    |  |\\   | |  |____ /  .  \\      |  |    |  |  |  | \n"
                 "             \\______|  |_______|    |__|    |__| \\__| |_______/__/ \\__\\     |__|    \\  /  \\  /  \n"
                 "\n"
                 " Welcome, Team getNext! \n"

                 "Get set to embark on an adventure through the cosmos! With each line of code, we're charting a course through the stars,"
                 "exploring new worlds, and encountering challenges along the way.\n"

                 "As the getNext team, our journey is just beginning. Together, our code will fuel this interstellar odyssey, crafting    a universe teeming with excitement and possibilities.\n"
                 "\n"
                 "So, let's compile our skills, ignite our imaginations, and launch into a universe of endless creativity. Welcome aboard, Team getNext! Let's code our way to the stars!\n"
                 "\n"


                 "                       |        |\n"
                 "                       |        |  //                 \\\\ | |\n"
                 "                       \\        | //                 /_\\\\| |         _.-~\n"
                 "                        \\       |||                 |  ||/ |     _.-~\n"
                 "                 ________\\      |||                  \\ ||  |__.-~\n"
                 "                /       /~`. ___\\||___________________/||_/______________\n"
                 "              _/_______/__/]---.               _____               ;:\n"
                 "             /         /( )/\\   `._____________\\    \\               :\n"
                 "            /         / /\\ \\    / .=============\\    \\             ::\n"
                 "           /         / / / /\\   | :  -WELCOME- | \\(_)_\\            ::\n"
                 "          /         / / / /-\\\\ _\\'   getNext() | |\\  \\             ::\n"
                 "         /        /' / / /._/.'_\".   SpaceShip | |/\\  \\            ::\n"
                 "        /        /  / / / - / _-  \\____________|_/ /\\  \\           ::\n"
                 "       /       /'  / / /-   |      \\====/\\======= /  \\_ \\           ::\n"
                 "      /       /   / : (  - -\\       \\_(/ /\\    / /    \\ \\           ::\n"
                 "     /...----'   /  . `. -   \\ -_   _'.\\\\ /|  / /|     \\ \\          ::\n"
                 "     \\           \\  /`. `._  /\\   _-    \\\\/  / / |      \\ \\         ::\n"
                 "      \\___________\\/  `. `._..'\\_______.'___/ /| |       \\ \\_       :\n"
                 "               /\".      `.....' |==========/ / \\ \\        \\_ \\      ::\n"
                 "              /-_   :  --..___ \\/       / / /   \\ \\         \\ \\_    ::\n"
                 "              |-._   :          \\      / / /     \\ \\         \\_ \\   ::\n"
                 "              |-_ '-._\\ - -_   - \\____/_/ /-      \\ \\     __   \\ \\   ::\n"
                 "        __..--|-      /\\          \\====/ /  \\      \\ \\_.-~  \\   \\ \\  ::\n"
                 "__..--~~.   . |     _.| \\          \\  / /  -     _. \\ \\      \\   \\ \\ ::\n"
                 "'  .  \"   .   |__.-'  |   \\__       \\/ /     _.-    \\_/      /    \\ \\ ::\n"
                 " __--~~  . .  |       |____\\ '----___\\/   _.-             _.-      \\ \\::\n"
                 "  __--\"\"      |       /====-\\        |    \\            _.-          \\ \\:\n"
                 " ..--~~ .- .. |  .    |     |        / _.- \\        _.-              \\_\\\n"
                 "   .   .      |_-     /     |_--  --/.-     \\    _.-________________________\n"
                 " . . .   .  . |      /______|______/      _.-\\_.-        ..    . \"  .  /\n"
                 "    .   .     |______|=====/\" -_- \"/   _.-      .    .            .   /\n"
                 " .       .    |\"     \"|   /--__   /_.-   .        .       .         ./\n"
                 ". .  .       /|___----|  /    -_ (____    .     .    .            . /\n"
                 "            / |   -   |_ |___________ \\  .    .           .    .   /\n"
                 " . .   .\"  / /|_-  -  \\ \\ \\___________/   .      .    .         . <\n"
                 "          /___\\ ______- /__/ /           .     .             .   . '-._\n"
                 " \". .  . /=====\\_______/==/ / ..     .      .      .      .       .    \"~~-.__\n"
                 "   .  . /_/ /          _//_/      .           .       .            .\n"
                 " . .  .    /           /         .       .       .          \" .      .\n"
                 "          /           /     .       .    \"    ,.        .       .           \"\n"
                 " . .     /           /   .        .         .       .       .         \"   .\n"
                 "  .   . / ___       / .         .        ..      \"      .         . ..       .\n"
                 "     __/_/  \\\\     /___    .      . .         .     .       \"             .\n"
                 "  .'  //     \\\\   /    `.\n"
                 ".'   /_|.\"..\".\\\\ /       `.   .         .       \"         .       .       .\n"
                 "      _|_______\\\\_         \\       . .    .        .            .     '  .\n"
                 "     \\___     ___/        // .          .     .        .               .\n"
                 "         \"---\"          .'/       .               .         .              .\n"
                 "`.                    .'.'   .        .               .            .    .\n"
                 "`.`.________________.'.'  .       .        .              .          .\n"
                 "  `.________________.'   \n"
                 ".     .          .          .         .        .          .      .\n"
                 "  .       .           .          .        .        .         .\n"
                 "       .      \"      .      \"                .         .\n"
                 "               .                .       \"         .               . .    \" ." <<"\n\n"<< std::endl;
}



void Printer::PrintFastShipASCII() {
    std::cout << "Your ship selection has been saved! You have selected a FAST ship.\n"
                 "          .          `. ___                  .             \n"
                 "       .            __,' __`.        *       _..----....____         \n"
                 "        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'      \n"
                 "  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'           \n"
                 ",'________________                          \\`-._`-','       ***        \n"
                 " `._              ```````````------...___   '-.._'-:      ***        \n"
                 "    ```--.._      ,.                     ````--...__\\-.***           \n"
                 "        .   `.--. `-`                       ____    |  |`** ** *           \n"
                 "              `. `.                       ,'`````.  ;  ;`** ** *            \n"
                 "   -            `._`.        __________   `.      \'__/`***               \n"
                 "                   `-:._____/______/___/____`.     \\  `   ***             \n"
                 "               *               |       `._    `.    \\        ***             \n"
                 "     o                         `._________`-.   `.   `.___               \n"
                 "                                                  `------'`\n" <<"\n\n"<< std::endl;
}

void Printer::PrintNormalShipASCII() {
    std::cout <<     "Your ship selection has been saved! You have selected a NORMAL ship.\n"
                     "      .           __|__       *       \n"
                     "                   _|_                -\n"
                     "           *      / _ \\       .      \n"
                     "   .           __/ (_) \\__           \n"
                     "          ____/_ ======= _\\____    *       \n"
                     " ________/ _ \\(_)_______(_)/ _ \\________    \n"
                     "<___+____ (_) | /   _   \\ | (_) ____+___>       \n"
                     "  O O O  \\___/ |   (_)   | \\___/  O O O        \n"
                     "             \\__\\_______/__/\n" <<"\n\n"<< std::endl;
}

void Printer::PrintStrongShipASCII() {
    std::cout << "Your ship selection has been saved! You have selected a STRONG ship.\n"
                 "    *                        ________         .          \n"
                 "                            `---.     `.          *      \n"
                 "             .                   \\      `.                \n"
                 "                                  )_______`.       .       \n"
                 "     .                          .'        //`---...___       \n"
                 "                   o           /         ||    // ||  `-._    .   \n"
                 "          *                 )`-|   =//=  ||   ||  ||  / ).`.     *  \n"
                 "       _............_       ).-|         ||   ||  `........'`-._   (o)\n"
                 "    .-'         `.----`.   _...'.....__  ||   ||  _____      ||-\\__.'\n"
                 "  .'|The Coolest| ).---.)  /_______..--'  ||   ||  -----    _ ||_/\n"
                 ".'_  |Alptekin|  ||   ||  `-------'      ||   ||   =\\=    \\_.'\n"
                 "|  | |Karabacak|  |'---'|    )`-|         ||   ||       _..-'         \n"
                 "'--'_____________|_____|    ).-| =\\=    ||    \\  _.-' ||            \n"
                 "|[]--------------/     /   __==\\          \\   _.-'    /o'\\     |     \n"
                 " \\     .--.     /    _...--''   '-.__......_.-'        \\__/    -o-      \n"
                 "  `-._//'o\\___.'---''             \\     .'                      |      \n"
                 "  ---  \\__/  -'             *      /    /               o            \n"
                 "                     o        ___.'    /          *          .       \n"
                 "                              `-------'  \n" << "\n\n"<<std::endl;
}

void Printer::PrintAsteroidASCII() {
    std::cout <<
              "Warning! You have entered the Asteroid Belt.\n"
              "                 ASTEROID BELT     \n"
              "                     .   *        .\n"
              "       *      -0-\n"
              "          .                .  *       - )-\n"
              "       .      *       o       .       *\n"
              " o                |\n"
              "           .     -O-\n"
              ".                 |        *      .     -0-\n"
              "       *  o     .    '       *      .        o\n"
              "              .         .        |      *\n"
              "   *             *              -O-          .\n"
              "         .             *         |     ,\n"
              "                .           o\n"
              "        .---.\n"
              "  =   _/__~0_\_     .  *            o       '\n"
              " = = (_________)             .\n"
              "                 .                        *\n"
              "       *               - ) -       *\n" << "\n\n" <<std::endl;
}

void Printer::PrintPlanetASCII() {
    std::cout << "Warning! You have entered the Abandoned Planet.\n"
                 "                       ABANDONED PLANET                   \n"
                 "o       .                _____---_____                    .\n"
                 "      .              .--\\             --.    .     .         .\n"
                 "     .             ./.;_.\\       __/~     \\.\n"
                 "                  /;  / `-'    __\\    .     \\.\n"
                 ".        .       / ,--'       / .   .;        \\        |\n"
                 "                | .|         /       __       |      -O-       .\n"
                 "               |__/      __ |  . ;   \\ | .     |      |\n"
                 "               |        /  \\_    . ;| \\___     |\n"
                 "  .    o       |        \\  .~\\___,--'          |    .       .\n"
                 "                |      | . ; ~~~~\\_    __     |\n"
                 "  |             \\     \\   .  .  ; \\  /_      /   .\n"
                 " -O-        .    \\    /         . |  ~       /                  .\n"
                 "  |    .          ~\\  \\   .      /       /~             o\n"
                 " .                   ~--___ ; ___-- ~\n"
                 "               .          ---         .            o .\n" <<"\n\n"<<std::endl;
}

void Printer::PrintPiratesASCII() {
    std::cout << "               SPACE PIRATES          \n"
                 "        /\\ \n"
                 "        ||_____-----_____-----_____\\ \n"
                 "        ||   O                  O  \\ \n"
                 "        ||    O\\    ___    //O     /\n"
                 "        ||       \\  /   \\ /        \\ \n"
                 "        ||         |_O O_|         /\n"
                 "        ||          ^ | ^          \\ \n"
                 "        ||        // *U* \\         /\n"
                 "        ||    O//  PIRATES   \\O    \\ \n"
                 "        ||   O    OF BIL142     O  /\n"
                 "        ||_____-----_____-----_____\\ \n"
                 "        ||\n"
                 "        ||\n"
                 "        ||\n" <<"\n\n"<<std::endl;
}

void Printer::PrintStatus(const std::shared_ptr<Ship>& ship) {
    std::cout << "Current Status:" << std::endl;
    std::cout << "Fuel: " << ship->GetFuel() << std::endl;
    std::cout << "Money: " << ship->GetMoney() << std::endl;
    std::cout << "Health: " << ship->GetHealth() << std::endl;
}

void Printer::PrintEndingMessage(GameState state, const std::shared_ptr<Ship>& ship) {
    if (state == win)
    {
        std::cout << R"(Congratulations!!!!! You Won!
                    __,--~--._
                 ,-;;;;   `;;;`\
                /;;;;;      ;;;;`\
              /;;;;;;     ___;;_; \
             /;;;;;;      \_ |;|;; |
            (;;;;;;       __||_|;;;|
             `\_,;;             ;_,`\
                `\___,-----'~~~~~    `\
                   \     GREAT         )
                    `\.__    JOB!     /'
                         `~~~~------~~)" <<std::endl;
    }
    else
    {
        std::cout << R"(Oops! You Lose. Try again!!!
                           ,--.
                          {    }
                          K,   }
                         /  `Y`
                    _   /   /
                   {_'-K.__/
                     `/-.__L._
                     /  ' /`\_}
                    /  ' /
            ____   /  ' /
     ,-'~~~~    ~~/  ' /_
   ,'             ``~~~%%',
  (                     %  Y
 {                      %% I
{      -                 %  `.
|       ',                %  )
|        |   ,..__      __. Y
|    .,_./  Y ' / ^Y   J   )|
\           |' /   |   |   ||
 \          L_/    . _ (_,.'(
  \,   ,      ^^""' / |      )
    \_  \          /,L]     /
      '-_`-,       ` `   ./`
         `-(_            )
             ^^\..___,.--`

)"<< std::endl;
    }

    std::cout << "Your Point:" << ((ship->GetFuel() * 5) + (ship->GetHealth() * 10) + (ship->GetMoney() * 10)) <<std::endl;
}
