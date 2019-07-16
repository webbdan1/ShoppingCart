#include "mpushbutton.h"

void mPushButton::beenClicked() {
    emit iChanged(this);
}
