
namespace Lynx\Annotation;

final class Parser {
    public static function parseAnnotations(var docComment)
    {
        var hasAnnotations, matches = [], anno, annoName, val, hasParams, params = [], param;
        let val = true;

        var rex = "/@(\w+)(?:\s*(?:\(\s*)?(.*?)(?:\s*\))?)??\s*(?:\n|\*\/)/";

        let hasAnnotations = preg_match_all(
            rex,
            docComment,
            matches,
            PREG_SET_ORDER
        );

        if (!hasAnnotations) {
            return [];
        }

        var annotations = [];

        for anno in matches {
			let annoName = strtolower(anno[1]);

			let val = true;
			if (isset(anno[2])) {
			    var regex1 = "/(\w+)\s*=\s*(\[[^\]]*\]|\"[^\"]*\"|[^,)]*)\s*(?:,|$)/";
				let hasParams = preg_match_all(regex1, anno[2], params, PREG_SET_ORDER);

				if (hasParams) {
					let val = [];
					for param in params {
					    //let val[param[1]] = self::_parseValue($param[2]);
					    let val[param[1]] = param[2];
					}
				} else {
					let val = trim(anno[2]);
					if (val == "") {
						let val = true;
					} else {
						//let val = self::_parseValue(val);
						let val = val;
					}
				}
			}

			if (isset(annotations[annoName])) {
				if (!is_array(annotations[annoName])) {
					let annotations[annoName] = [annotations[annoName]];
				}
				let annotations[$annoName][] = val;
			} else {
				let annotations[annoName] = val;
			}
		}

		return annotations;
    }
}