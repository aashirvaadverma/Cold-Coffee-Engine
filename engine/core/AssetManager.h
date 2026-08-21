#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "Texture.h"

class AssetManager
{
public:
    bool Initialize(SDL_Renderer* renderer);

    Texture* LoadTexture(const std::string& path);
    Texture* GetTexture(const std::string& path) const;

    bool HasTexture(const std::string& path) const;

    void Shutdown();

private:
    SDL_Renderer* m_Renderer = nullptr;

    std::unordered_map<std::string, std::unique_ptr<Texture>> m_Textures;
};