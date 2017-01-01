#pragma once

#include <utils/headers/common.hpp>
#include <components/component.hpp>
#include <components/geometry/quad.hpp>
#include <rendering/shader.hpp>
#include <data/store.hpp>

namespace Engine
{
  namespace Components
  {
    /** \class Material
     *
     * \brief Link between an actual shader and its data, contained in a Store.
     */
    class Material
      : public Component, public std::enable_shared_from_this<Material>
    {
      public:
        typedef std::shared_ptr<Material> MaterialPtr;

      public:
        Material();
        ~Material();

      public:
        bool unique() override;

      public:
        void
        sendUniforms();

      public:
        /** \brief Set the pointer to the actual shader using this material.
         *
         * \param shader
         * the pointer to the shader using this material.
         */
        void
        set_shader(Rendering::Shader::ShaderPtr shader);

      public:
        const Rendering::Shader::ShaderPtr&
        get_shader() const;

        const GLuint&
        get_material_id() const;

        const Data::Store&
        get_store() const;

      protected:
        Rendering::Shader::ShaderPtr  shader_;
        GLuint                        material_id_;
        Data::Store                   store_;

      private:
        static GLuint ID;

    };
  } // namespace Component
} // namespace Engine
