#include "ViZDoom.h"

#include <stdint.h>

extern "C" {

enum DoomGameStatus {
  DOOM_GAME_STATUS_Success = 0,
  DOOM_GAME_STATUS_Failure,
  DOOM_GAME_STATUS_VizdoomUnexpectedExitException,
  DOOM_GAME_STATUS_UnknownException,
};

vizdoom::DoomGame *DoomGame_new() {
  return new vizdoom::DoomGame();
}

void DoomGame_delete(vizdoom::DoomGame *game) {
  delete game;
}

DoomGameStatus DoomGame_init(vizdoom::DoomGame *game) {
  try {
    if (game->init()) {
      return DOOM_GAME_STATUS_Success;
    } else {
      return DOOM_GAME_STATUS_Failure;
    }
  }
  catch (vizdoom::ViZDoomUnexpectedExitException e) {
    return DOOM_GAME_STATUS_VizdoomUnexpectedExitException;
  }
  catch (...) {
    return DOOM_GAME_STATUS_UnknownException;
  }
}

void DoomGame_close(vizdoom::DoomGame *game) {
  game->close();
}

void DoomGame_newEpisode(vizdoom::DoomGame *game) {
  game->newEpisode();
}

int DoomGame_isRunning(vizdoom::DoomGame *game) {
  return game->isRunning();
}

double DoomGame_makeAction(vizdoom::DoomGame *game, const double *actions_ptr, size_t actions_len, unsigned int ticks) {
  std::vector<double> actions;
  for (size_t j = 0; j < actions_len; j++) {
    actions.push_back(actions_ptr[j]);
  }
  return game->makeAction(actions, ticks);
}

int DoomGame_isNewEpisode(vizdoom::DoomGame *game) {
  return game->isNewEpisode();
}

int DoomGame_isEpisodeFinished(vizdoom::DoomGame *game) {
  return game->isEpisodeFinished();
}

int DoomGame_isPlayerDead(vizdoom::DoomGame *game) {
  return game->isPlayerDead();
}

vizdoom::GameState *DoomGame_getState(vizdoom::DoomGame *game) {
  vizdoom::GameStatePtr state = game->getState();
  return state.get();
}

size_t DoomGame_getAvailableButtonsSize(vizdoom::DoomGame *game) {
  return game->getAvailableButtonsSize();
}

double DoomGame_getButtonMaxValue(vizdoom::DoomGame *game, vizdoom::Button button) {
  return game->getButtonMaxValue(button);
}

double DoomGame_getLivingReward(vizdoom::DoomGame *game) {
  return game->getLivingReward();
}

double DoomGame_getDeathPenalty(vizdoom::DoomGame *game) {
  return game->getDeathPenalty();
}

double DoomGame_getLastReward(vizdoom::DoomGame *game) {
  return game->getLastReward();
}

int DoomGame_loadConfig(vizdoom::DoomGame *game, const char *filename_ptr, size_t filename_len) {
  std::string filename(filename_ptr, filename_len);
  bool result = game->loadConfig(filename);
  return result;
}

vizdoom::Mode DoomGame_getMode(vizdoom::DoomGame *game) {
  return game->getMode();
}

void DoomGame_setMode(vizdoom::DoomGame *game, vizdoom::Mode mode) {
  game->setMode(mode);
}

unsigned int DoomGame_getSeed(vizdoom::DoomGame *game) {
  return game->getSeed();
}

void DoomGame_setSeed(vizdoom::DoomGame *game, unsigned int seed) {
  return game->setSeed(seed);
}

unsigned int DoomGame_getEpisodeTimeout(vizdoom::DoomGame *game) {
  return game->getEpisodeTimeout();
}

void DoomGame_setEpisodeTimeout(vizdoom::DoomGame *game, unsigned int ticks) {
  game->setEpisodeTimeout(ticks);
}

unsigned int DoomGame_getEpisodeTime(vizdoom::DoomGame *game) {
  return game->getEpisodeTime();
}

void DoomGame_setScreenResolution(vizdoom::DoomGame *game, vizdoom::ScreenResolution resolution) {
  game->setScreenResolution(resolution);
}

vizdoom::ScreenFormat DoomGame_getScreenFormat(vizdoom::DoomGame *game) {
  return game->getScreenFormat();
}

void DoomGame_setScreenFormat(vizdoom::DoomGame *game, vizdoom::ScreenFormat format) {
  game->setScreenFormat(format);
}

void DoomGame_setWindowVisible(vizdoom::DoomGame *game, int visibility) {
  game->setWindowVisible(visibility);
}

void DoomGame_setConsoleEnabled(vizdoom::DoomGame *game, int console) {
  game->setConsoleEnabled(console);
}

void DoomGame_setSoundEnabled(vizdoom::DoomGame *game, int sound) {
  game->setSoundEnabled(sound);
}

size_t DoomGame_getScreenSize(vizdoom::DoomGame *game) {
  return game->getScreenSize();
}

size_t DoomGame_getScreenPitch(vizdoom::DoomGame *game) {
  return game->getScreenPitch();
}

size_t DoomGame_getScreenWidth(vizdoom::DoomGame *game) {
  return game->getScreenWidth();
}

size_t DoomGame_getScreenHeight(vizdoom::DoomGame *game) {
  return game->getScreenHeight();
}

size_t DoomGame_getScreenChannels(vizdoom::DoomGame *game) {
  return game->getScreenChannels();
}

} // extern "C"
