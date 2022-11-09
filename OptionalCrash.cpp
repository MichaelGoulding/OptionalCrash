#include <optional>
#include <map>

class Foo
{
private:
    struct MaximizedViewId
    {
        int type;
        std::optional<int> id;

        auto operator<=>(const MaximizedViewId &) const = default;

        // If you comment out the line above and uncomment out the below, it compiles fine.
        //bool operator<(const MaximizedViewId & right) const
        //{
        //    return std::tie(type, id) < std::tie(right.type, right.id);
        //}
    };

    void foo()
    {
        std::map<MaximizedViewId, int> maximizableViews;
        maximizableViews[MaximizedViewId{ 1 }] = 1;
    }
};

int main()
{
}
