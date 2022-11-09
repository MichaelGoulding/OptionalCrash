#include <optional>
#include <map>
#include <memory>

class Foo
{
private:

    enum class MaximizedViewType
    {
        Schematic,
        RunAccuracy,
        HistoricalAccuracy,
    };

    struct MaximizedViewId
    {
        MaximizedViewType type;
        std::optional<int> qubitId;

        auto operator<=>(const MaximizedViewId &) const = default;

        // If you comment out the line above and uncomment out the below, it compiles fine.
        //bool operator<(const MaximizedViewId & right) const
        //{
        //    return std::tie(type, qubitId) < std::tie(right.type, right.qubitId);
        //}
    };

    void foo()
    {
        std::map<MaximizedViewId, int> maximizableViews;
        maximizableViews[MaximizedViewId{ MaximizedViewType::Schematic }] = 1;
    }
};

int main()
{
}
