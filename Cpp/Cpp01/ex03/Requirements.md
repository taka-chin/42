# Weaponクラス
## private:
	std::string type
## public:
	getter
	setter

# HumanAクラス
## private:
	std::string name
	Weapon &weapon
## public:
	attack();
	getter
	setter

# HumanBクラス
## private:
	std::string name
	Weapon &weapon
## public:
	attack();
	getter
	setter
	setWeapon

# Diff HumanA and HumanB
## While HumanA takes the Weapon in its constructor, HumanB doesn’t.
## HumanB may not always have a Weapon, whereas HumanA will always be armed.
