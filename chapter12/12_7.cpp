#include <string_view>
#include <array>
#include <algorithm>
#include <iostream>

struct Student
{
	std::string_view name;
	int points;
};

constexpr std::array<Student, 8> students{
    {
        { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 }
    }
};

void getMaxScoreStudent()
{
    auto compareStudents{ [](const Student& student1, const Student& student2)
        {return student1.points < student2.points; }
    };
    auto max{ std::max_element(students.begin(), students.end(), compareStudents) };
    std::cout << max->name << " is the best student\n";
}


struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

std::array<Season, 4> seasons{
  { { "Spring", 285.0 },
    { "Summer", 296.0 },
    { "Fall", 288.0 },
    { "Winter", 263.0 } }
};

void sortSeasons()
{
    auto sort{ [](const Season& a, const Season& b)
        {return a.averageTemperature < b.averageTemperature; }
    };
    std::sort(seasons.begin(), seasons.end(), sort);
    /*
     * Use std::sort here
     */

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }

}

