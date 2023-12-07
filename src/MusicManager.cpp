#include "MusicManager.h"

bool MusicManager::openFromFile(const std::string& path) {
    if (!music.openFromFile(path)) {
        return false;
    }
    return true;
}

void MusicManager::play() {
    music.play();
}