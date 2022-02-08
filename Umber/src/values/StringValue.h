#pragma once

#include "../Value.h"
#include "../Position.h"
#include "../utils/Utils.h"

namespace umber
{

	namespace values
	{

		class StringValue : public Value
		{
		private:
			std::string m_value;

		public:
			StringValue(std::string value, Position pos_start, Position pos_end, std::shared_ptr<Context> context);
			StringValue(std::string value);

			inline const std::string& value() const { return this->m_value; }

			std::pair<std::unique_ptr<Value>, std::unique_ptr<errors::RuntimeError>> added_to(std::shared_ptr<Value> other) override;

			std::unique_ptr<Value> copy() const override;

			inline std::string as_string() const override { return utils::std_string_format("\"%s\"", m_value.c_str()); }

		};

	}

}