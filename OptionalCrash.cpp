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
