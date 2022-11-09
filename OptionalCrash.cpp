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

    using IScene = int;

    std::map<MaximizedViewId, std::shared_ptr<IScene>> _maximizableViews;
    std::shared_ptr<IScene> _maximizedView;

    void foo()
    {
        _maximizableViews[MaximizedViewId{ MaximizedViewType::Schematic }] = std::make_shared<IScene>(1);
    }
};




int main()
{
}
