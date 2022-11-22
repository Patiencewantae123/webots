// Copyright 1996-2023 Cyberbotics Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "WbWrenAbstractPostProcessingEffect.hpp"

#include "WbWrenOpenGlContext.hpp"
#include "WbWrenPostProcessingEffects.hpp"
#include "WbWrenRenderingContext.hpp"

#include <wren/post_processing_effect.h>
#include <wren/viewport.h>

WbWrenAbstractPostProcessingEffect::WbWrenAbstractPostProcessingEffect() :
  mWrenViewport(NULL),
  mWrenPostProcessingEffect(NULL),
  mHasBeenSetup(false) {
}

WbWrenAbstractPostProcessingEffect::~WbWrenAbstractPostProcessingEffect() {
  if (mWrenViewport)
    wr_viewport_remove_post_processing_effect(mWrenViewport, mWrenPostProcessingEffect);

  wr_post_processing_effect_delete(mWrenPostProcessingEffect);
}

void WbWrenAbstractPostProcessingEffect::detachFromViewport() {
  if (mWrenViewport) {
    wr_viewport_remove_post_processing_effect(mWrenViewport, mWrenPostProcessingEffect);
    wr_post_processing_effect_delete(mWrenPostProcessingEffect);
    mWrenPostProcessingEffect = NULL;
    mWrenViewport = NULL;
    mHasBeenSetup = false;
  }
}
