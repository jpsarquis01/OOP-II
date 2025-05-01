#pragma once


class GameManager
{
public:
    // gets access to the manager
    static GameManager* Get();

    // delete copy/move constructors
    GameManager(GameManager&) = delete;             // copy constructor
    GameManager(GameManager&&) = delete;            // move constructor
    GameManager& operator=(GameManager&) = delete;  // copy operator
    GameManager& operator=(GameManager&&) = delete; // move operator

    // singleton functions
    void Initialize();
    void Terminate();
    void Update();

private:
    // hide constructor, only singleton can create
    GameManager() = default;

    // any private functions/variables for the system
};