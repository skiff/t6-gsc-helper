#pragma once

#define SELECT(mp, zm) (game::is_mp() ? mp : zm)

namespace game
{
	enum gamemode
	{
		none,
		multiplayer,
		zombies
	};

	extern gamemode current;

	bool is_mp();
	bool is_zm();
	void set_mode();

	template <typename T> class symbol
	{
	public:
		symbol(const size_t mp_a, const size_t zm_a) : mp_(reinterpret_cast<T*>(mp_a)), zm_(reinterpret_cast<T*>(zm_a))
		{
		}

		T* get() const
		{
			return game::is_mp() ? mp_ : zm_;
		}

		operator T* () const
		{
			return this->get();
		}

		T* operator->() const
		{
			return this->get();
		}

	private:
		T* mp_;
		T* zm_;
	};
}