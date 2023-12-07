#include <SFML/Audio.hpp>

class MusicManager {
public:
    sf::Music music;
    bool openFromFile(const std::string& path);
    void play();
};