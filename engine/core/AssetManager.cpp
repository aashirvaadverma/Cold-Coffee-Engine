#include "AssetManager.h"

bool AssetManager::Initialize(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
    return true;
}

Texture* AssetManager::LoadTexture(const std::string& path)
{
    // Check if this texture is already loaded.
    auto existing = m_Textures.find(path);

    if (existing != m_Textures.end())
    {
        return existing->second.get();
    }

    auto texture = std::make_unique<Texture>();

    if (!texture->Load(m_Renderer, path))
    {
        return nullptr;
    }

    Texture* texturePointer = texture.get();

    m_Textures.emplace(path, std::move(texture));

    return texturePointer;
}

Texture* AssetManager::GetTexture(const std::string& path) const
{
    auto existing = m_Textures.find(path);

    if (existing == m_Textures.end())
    {
        return nullptr;
    }

    return existing->second.get();
}

bool AssetManager::HasTexture(const std::string& path) const
{
    return m_Textures.find(path) != m_Textures.end();
}

void AssetManager::Shutdown()
{
    m_Textures.clear();
    m_Renderer = nullptr;
}