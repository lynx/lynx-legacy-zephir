
namespace Lynx\Annotation;

final class Parser {
	const ANNOTATION_REGEX = "/@(\w+)(?:\s*(?:\(\s*)?(.*?)(?:\s*\))?)??\s*(?:\n|\*\/)/";

    public static function parseAnnotations(var docComment)
    {
        var hasAnnotations, matches = [];

        let hasAnnotations = preg_match_all(
            self::ANNOTATION_REGEX,
            docComment,
            matches,
            PREG_SET_ORDER
        );

        if (!hasAnnotations) {
            return [];
        }
    }
}