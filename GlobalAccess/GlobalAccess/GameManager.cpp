#include "GameManager.h"

GameManager* GameManager::Get()
{
    static GameManager sInstance;
    return &sInstance;
}
void GameManager::Initialize()
{
    // do anything that needs to be initialized
}
void GameManager::Terminate()
{
    // terminate everything
}
void GameManager::Update()
{
    // update whatever
}