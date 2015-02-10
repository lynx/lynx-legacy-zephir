/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */

namespace Lynx\Annotation;

final class RegexDocParser
{
    /**
     * @return array
     */
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
                        let val[param[1]] = self::parseValue(param[2]);
                        //let val[param[1]] = param[2];
                    }
                } else {
                    let val = trim(anno[2]);
                    if (val == "") {
                        let val = true;
                    } else {
                        let val = self::parseValue(val);
                        //let val = val;
                    }
                }
            }

            if (isset(annotations[annoName])) {
                if (!is_array(annotations[annoName])) {
                    let annotations[annoName] = [annotations[annoName]];
                }
                let annotations[annoName][] = val;
            } else {
                let annotations[annoName] = val;
            }
        }

        return annotations;
    }


    /**
     * @return mixed
     */
    private static function parseValue(var value)
    {
        var val, vals, v;

        let val = trim(value);

        if (substr(val, 0, 1) == "[" && substr(val, -1) == "]") {
            // Array values
            let vals = explode(',', substr(val, 1, -1));
            let val = [];

            for v in vals {
                let val[] = self::parseValue(v);
            }

            return val;
        } else {
            if (substr(val, 0, 1) == "{" && substr(val, -1) == "}") {
                // If is json object that start with { } decode them
                return json_decode(val);
            } else {
                if (substr(val, 0, 1) == "\"" && substr(val, -1) == "\"") {
                    // Quoted value, remove the quotes then recursively parse and return
                    let val = substr(val, 1, -1);
                    return self::parseValue(val);
                } else {
                    if (strtolower(val) == "true") {
                        // Boolean value = true
                        return true;
                    } else {
                        if (strtolower(val) == "false") {
                            // Boolean value = false
                            return false;
                        } else {
                            if (is_numeric(val)) {
                                // Numeric value, determine if int or float and then cast
                                if ((float) val == (int) val) {
                                    return (int) val;
                                } else {
                                    return (float) val;
                                }
                            }
                        }
                    }
                }
            }
        }

        // Nothing special, just return as a string
        return val;
    }
}
