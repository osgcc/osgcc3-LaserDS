#include <nds.h>

#include "camera.h"

void Camera::apply()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-x * 2, -y * 2, 0);
}