#include <stdafx.hpp>

namespace gsc
{
	namespace value
	{
		template<> void add(game::gentity_s* value)
		{
			game::Scr_AddEntity(game::SCRIPTINSTANCE_SERVER, value);
		}

		template<> void add(int value)
		{
			game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, value);
		}

		template<> void add(float value)
		{
			game::Scr_AddFloat(game::SCRIPTINSTANCE_SERVER, value);
		}

		template<> void add(const char* value)
		{
			game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, value);
		}

		template<> void add(float* value)
		{
			game::Scr_AddVector(game::SCRIPTINSTANCE_SERVER, value);
		}

		template<> game::gentity_s* get(int index)
		{
			return game::Scr_GetEntity(game::SCRIPTINSTANCE_SERVER, index);
		}

		template<> float get(int index)
		{
			return game::Scr_GetFloat(game::SCRIPTINSTANCE_SERVER, index);
		}

		template<> int get(int index)
		{
			return game::Scr_GetInt(game::SCRIPTINSTANCE_SERVER, index);
		}

		template<> const char* get(int index)
		{
			return game::Scr_GetString(game::SCRIPTINSTANCE_SERVER, index);
		}

		template<> float* get(int index)
		{
			static float vec[3] = { 0 };

			memset(vec, 0, sizeof(float) * 3);
			game::Scr_GetVector(game::SCRIPTINSTANCE_SERVER, index, vec);
			return vec;
		}
	}

	namespace array
	{
		void create()
		{
			game::Scr_MakeArray(game::SCRIPTINSTANCE_SERVER);
		}

		template<> void set(const std::string& index, game::gentity_s* value)
		{
			game::Scr_AddEntity(game::SCRIPTINSTANCE_SERVER, value);
			game::Scr_AddArrayStringIndexed(game::SCRIPTINSTANCE_SERVER, game::SL_GetString(index.data(), 0));
		}

		template<> void set(const std::string& index, float value)
		{
			game::Scr_AddFloat(game::SCRIPTINSTANCE_SERVER, value);
			game::Scr_AddArrayStringIndexed(game::SCRIPTINSTANCE_SERVER, game::SL_GetString(index.data(), 0));
		}

		template<> void set(const std::string& index, int value)
		{
			game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, value);
			game::Scr_AddArrayStringIndexed(game::SCRIPTINSTANCE_SERVER, game::SL_GetString(index.data(), 0));
		}

		template<> void set(const std::string& index, const char* value)
		{
			game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, value);
			game::Scr_AddArrayStringIndexed(game::SCRIPTINSTANCE_SERVER, game::SL_GetString(index.data(), 0));
		}

		template<> void set(const std::string& index, float* value)
		{
			game::Scr_AddVector(game::SCRIPTINSTANCE_SERVER, value);
			game::Scr_AddArrayStringIndexed(game::SCRIPTINSTANCE_SERVER, game::SL_GetString(index.data(), 0));
		}

		template<> void set(game::gentity_s* value)
		{
			game::Scr_AddEntity(game::SCRIPTINSTANCE_SERVER, value);
			game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);
		}

		template<> void set(float value)
		{
			game::Scr_AddFloat(game::SCRIPTINSTANCE_SERVER, value);
			game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);
		}

		template<> void set(int value)
		{
			game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, value);
			game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);
		}

		template<> void set(const char* value)
		{
			game::Scr_AddString(game::SCRIPTINSTANCE_SERVER, value);
			game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);
		}

		template<> void set(float* value)
		{
			game::Scr_AddVector(game::SCRIPTINSTANCE_SERVER, value);
			game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);
		}
	}

	namespace notify
	{
		std::unique_ptr<notify_params> create(const std::string& value)
		{
			auto notify_ = std::make_unique<notify_params>(value);
			return notify_;
		}

		void notify_params::send()
		{
			game::Scr_NotifyLevel(this->notify_string.data());
		}

		void notify_params::send(game::gentity_s* entity)
		{
			game::Scr_Notify(entity, game::SL_GetString(this->notify_string.data(), 0), this->paramcount);
		}

		void notify_params::send(int entity_num)
		{
			game::Scr_NotifyNum(entity_num, 0, game::SL_GetString(this->notify_string.data(), 0), this->paramcount);
		}
	}
}