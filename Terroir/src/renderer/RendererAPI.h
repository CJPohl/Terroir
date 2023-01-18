#ifndef TERROIR_RENDERERAPI_H
#define TERROIR_RENDERERAPI_H

#include "VertexArray.h"
#include <glm/vec4.hpp>
#include <memory>

namespace Terroir
{

class RendererAPI
{
  public:
    virtual ~RendererAPI() = default;

    enum class API
    {
        None = 0,
        OpenGL = 1,
        Direct = 2,
        Vulkan = 3,
        Metal = 4,
    };

    virtual void Clear() = 0;
    virtual void Clear(const glm::vec4 &) = 0;

    virtual void DrawIndexed(const std::shared_ptr<VertexArray> &) = 0;

    static API GetAPI()
    {
        return s_API;
    }

  private:
    static API s_API;
};

} // namespace Terroir

#endif // !TERROIR_RENDERERAPI_H
