#pragma once
#include <string>
#include <iostream>

class Exception
{

private:
	std::string text;
	unsigned short line;
	std::string file_name;

public:

	Exception(const std::string& text, const short& line, const std::string& file_name)
	{
		Set_text(text);
		Set_line(line);
		Set_file_name(file_name);
	}

	void Set_text(const std::string& text)
	{
		this->text = text;
	}

	std::string Get_text() const
	{
		return text;
	}
	

	void Set_line(const short& line)
	{
		this->line = line;
	}

	unsigned short Get_line() const
	{
		return line;
	}

	void Set_file_name(const std::string& file_name)
	{
		this->file_name = file_name;
	}

	std::string Get_file_name() const
	{
		return file_name;
	}

	friend std::ostream& operator << (std::ostream& out, const Exception& exception);

};


class DatabaseException : public Exception
{
public:

	DatabaseException(const std::string& text, const short& line, const std::string& file_name)
		:Exception(text, line, file_name)
	{}

};


class InvalidArgumentException : public Exception
{
public:

	InvalidArgumentException(const std::string& text, const short& line, const std::string& file_name)
		:Exception(text, line, file_name)
	{}

};



std::ostream& operator << (std::ostream& out, const Exception& exception)
{
	out << "Exception Text: " << exception.Get_text() << '\n';
	out << "Exception Line: " << exception.Get_line() << '\n';
	out << "Exception File Name: " << exception.Get_file_name() << "\n\n";

	return out;
}
