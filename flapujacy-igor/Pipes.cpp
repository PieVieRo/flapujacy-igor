#include "Pipes.hpp"

Pipes::Pipes(SDL_Texture* ruraTekstura, int offset) : gornaRura(1280, 0, 20+offset, 96, ruraTekstura, false), dolnaRura(1280,20+offset+180,720-(20+offset+180), 96, ruraTekstura, false)
{
}

Entity* Pipes::get_gornaRura() {
	return &this->gornaRura;
}

Entity* Pipes::get_dolnaRura() {
	return &this->dolnaRura;
}

void Pipes::move(float delta) {
	this->gornaRura.move(delta);
	this->dolnaRura.move(delta);
}

void Pipes::checkCollision(Entity* igor) {
	if (!(gornaRura.get_x() < igor->get_x() + 96 && gornaRura.get_x() + 96 > igor->get_x()))
		return;
	if(!(gornaRura.get_y()+gornaRura.get_desired_h() > igor->get_y() || dolnaRura.get_y() < igor->get_y()+igor->get_desired_h()))
		return;

	igor->die();
}

bool Pipes::checkOOB() {
	return gornaRura.get_x() + 96 <= 0;
}
