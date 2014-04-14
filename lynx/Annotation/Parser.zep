
namespace Lynx\Annotation;

final class Parser {
    public static function parseAnnotations(var docComment)
    {
        var hasAnnotations, matches = [];

        let hasAnnotations = preg_match_all(
            "/@(\w+)(?:\s*(?:\(\s*)?(.*?)(?:\s*\))?)??\s*(?:\n|\*\/)/",
            docComment,
            matches,
            PREG_SET_ORDER
        );

        if (!hasAnnotations) {
            return [];
        }
    }
}