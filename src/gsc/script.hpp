#pragma once

namespace gsc
{
	namespace value
	{
		template<typename T> void add(T value);
		template<typename T> T get(int index);
	}

	namespace array
	{
		void create();

		template<typename T> void set(const std::string& index, T value);
		template<typename T> void set(T value);
	}

	namespace notify
	{
		class notify_params
		{
		public:
			notify_params(const std::string& value) : notify_string(value) {}

			template<typename T> void add(T value)
			{
				value::add<T>(value);
				this->paramcount++;
			}

			void send();
			void send(game::gentity_s* entity);
			void send(int entity_num);

		private:
			int paramcount;
			std::string notify_string;
		};

		std::unique_ptr<notify_params> create(const std::string& value);
	}
}