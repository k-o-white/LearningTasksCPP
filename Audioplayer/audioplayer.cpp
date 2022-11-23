#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

class Track
{
private:
  std::string name;
  std::tm creationDate;
  std::time_t duration;
public:
  std::time_t tm = std::time(nullptr);
  Track()
  {
    name = "unknown";
    creationDate = *std::localtime(&tm);
    duration = std::time(0);
  }

  std::string getName()
  {
    return name;
  }

  std::tm getCreationDate()
  {
    return creationDate;
  }

  std::time_t getDuration()
  {
    return duration;
  }

  void setName(const std::string &newName)
  {
    name = newName;
  }

  void setCreationDate(const std::tm &newCreationDate)
  {
    creationDate = newCreationDate;
  }

  void setDuration(const std::time_t &newDuration)
  {
    duration = newDuration;
  }
};

class Player
{
public:
  std::vector <Track> playlist;
  Track playingTrack;
  bool isPlaying = false;
  bool isPause = false;
  bool isPlaylistEmpty = false;

  void initialisePlaylist()
  {
    std::time_t tm = std::time(nullptr);
    std::fstream file("playlist.txt");
    if(!file.is_open())
    {
      std::cout << "Playlist is empty." << std::endl;
      std::cout << "Program will be finished." << std::endl;
      isPlaylistEmpty = true;
      return;
    }

    while(!file.eof())
    {
      Track tempTrack;
      std::string name;
      file >> name;
      tempTrack.setName(name);
      std::tm tempCreationDate;
      std::string year, month, day, foo;
      file >> year >> month >> day;
      tempCreationDate.tm_year = std::stoi(year) - 1900;
      tempCreationDate.tm_mon = std::stoi(month) - 1;
      tempCreationDate.tm_mday = std::stoi(day);
      tempTrack.setCreationDate(tempCreationDate);
      std::tm tempDuration = *std::localtime(&tm);
      file >> tempDuration.tm_min >> tempDuration.tm_sec;
      std::time_t tempDur = std::time_t(tempDuration.tm_min * 60 + tempDuration.tm_sec);
      tempTrack.setDuration(tempDur);
      playlist.push_back(tempTrack);
    }
    file.close();
  }

  void playing()
  {
    std::cout << playingTrack.getName() << std::endl;
    std::tm nowPlaying = playingTrack.getCreationDate();
    std::cout << std::put_time(&nowPlaying, "%Y/%m/%d") << std::endl;
    if ((playingTrack.getDuration() / 60) < 10)
      std::cout << "0" << playingTrack.getDuration() / 60;
    else
      std::cout << playingTrack.getDuration() / 60;
    std::cout << ":";
    if ((playingTrack.getDuration() % 60) < 10)
      std::cout << "0" << playingTrack.getDuration() % 60;
    else
      std::cout << playingTrack.getDuration() % 60;
    std::cout << std::endl;
  }

  void play()
  {
    std::system("clear");
    if (isPlaying)
    {
      std::cout << "Player is working now." << std::endl;
      playing();
      return;
    }
    else
    {
      if (playingTrack.getName() != "unknown")
      {
        isPlaying = true;
        playing();
      }
      else
      {
        std::string input;
        std::cout << "Input track name: ";
        std::cin >> input;
        bool found = false;
        for (int i = 0; i < playlist.size(); ++i)
        {
          if (playlist[i].getName() == input)
          {
            playingTrack = playlist[i];
            found = true;
            break;
          }
        }
        if (found)
        {
          isPlaying = true;
          playing();
        }
        else
        {
          std::cout << "Track isn't found." << std::endl;
        }
      }
    }
  }

  void pause()
  {
    std::system("clear");
    if (!isPlaying)
    {
      std::cout << "Player isn't working now." << std::endl;
      return;
    }
    if (!isPause)
    {
      isPlaying = false;
      isPause = true;
      std::cout << playingTrack.getName() << " was paused." << std::endl;
    }
    else
    {
      std::system("clear");
      std::cout << "You can't pause track now." << std::endl;
      playing();
    }
  }

  void stop()
  {
    std::system("clear");
    if (isPlaying || isPause)
    {
      isPlaying = false;
      isPause = false;
      std::cout << playingTrack.getName() << " was stopped." << std::endl;
      playingTrack = Track();
    }
    else
      std::cout << "Player isn't working now." << std::endl;
  }

  void next()
  {
    if (isPlaying || isPause)
      stop();
    playingTrack = playlist[std::rand() % playlist.size()];
    play();
  }

  void display()
  {
    std::system("clear");
    std::cout << "Playlist: " << std::endl;
    for(int i = 0; i < playlist.size(); ++i)
      std::cout << playlist[i].getName() << std::endl;
  }
};

void instruction()
{
  std::cout << std::endl;
  std::cout << "------------------ How to use it. ------------------" << std::endl;
  std::cout << "play    - choosing track and playing it or return playing paused track;" << std::endl;
  std::cout << "pause   - pausing current playing track (you may pause track only once per play);" << std::endl;
  std::cout << "stop    - stop current playing track;" << std::endl;
  std::cout << "next    - playing random track;" << std::endl;
  std::cout << "display - display tracks in playlist;" << std::endl;
  std::cout << "exit    - finish program." << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << std::endl;
}

int main()
{
  std::srand(std::time(nullptr));
  Player* myPlayer = new Player();
  myPlayer->initialisePlaylist();
  if (myPlayer->isPlaylistEmpty)
    return 0;
  std::string input;
  std::cout << "Welcome to audio player!" << std::endl;
  instruction();
  std::cout << "Input command: ";
  std::cin >> input;
  while (input != "exit")
  {
    if (input == "play")
      myPlayer->play();
    else if (input == "pause")
      myPlayer->pause();
    else if (input == "stop")
      myPlayer->stop();
    else if (input == "next")
      myPlayer->next();
    else if (input == "display")
      myPlayer->display();
    else
      std::cout << "Wrong command." << std::endl;

    instruction();
    std::cout << "Input command: ";
    std::cin >> input;
  }
  delete myPlayer;
  myPlayer = nullptr;
  return 0;
}
