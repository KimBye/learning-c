#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <random>
#include <cmath>

class hotColdGame
{
public:
  hotColdGame(std::string name, int lowest, int highest)
  {
    userName = name;
    min = lowest;
    max = highest;
    margin = 0.1;
    restart();
  }
  std::string restart()
  {
    generate();
    if (hiddenNumber >= min & hiddenNumber <= max)
    {
      return "successful generated!";
    }
    return "failed";
  }
  std::string reset(int lowest, int highest)
  {
    generate();
    if (hiddenNumber >= min & hiddenNumber <= max)
    {
      return "Welcome! " + userName + " to HOTCOLD game.";
    }
    return "Unable to restart";
  }
  std::string isIt(int num)
  {
    numOfGuess += 1;
    if (num == hiddenNumber)
    {
      std::string message = "Well done! you did it.";
      if (numOfGuess <= 1)
      {
        return message + " Only guess! You are psychic. o.O";
      }
      return std::string(message) + std::string(" ") + std::to_string(numOfGuess) + std::string(" guesses before you got");
    }
    else if (num < rangeMin or num > rangeMax)
    {
      return "Cold";
    }
    return "Warm";
  }

private:
  int hiddenNumber;
  int min;
  int max;
  int numOfGuess;
  double margin;
  int rangeMin;
  int rangeMax;
  std::string userName;
  void generate()
  {
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(min, max);
    hiddenNumber = dist(engine);
    int result = ceil((hiddenNumber * margin));
    rangeMax = hiddenNumber + result;
    rangeMin = hiddenNumber - result;
  }
};

int main()
{
  std::string userName;
  int min;
  int max;
  std::string result = "";

  std::cout << "Please enter your name: " << std::endl;
  std::cin >> userName;
  std::cout << "Please enter lowest value it holds: " << std::endl;
  std::cin >> min;
  std::cout << "Please enter highest value it holds: " << std::endl;
  std::cin >> max;

  hotColdGame game(userName, min, max);
  std::string::size_type sub = result.find("Well done!", 0);

  while (sub == std::string::npos)
  {
    int ans;
    getc(stdin);
    std::cout << "Please enter your guess here?" << std::endl;
    std::cin >> ans;
    result = game.isIt(ans);
    std::cout << result << std::endl;
    sub = result.find("Well done!", 0);
  }
  return (0);
}