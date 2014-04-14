<?php

namespace Lynx\Annotation;

final class Parser
{
	const ANNOTATION_REGEX = "/@(\w+)(?:\s*(?:\(\s*)?(.*?)(?:\s*\))?)??\s*(?:\n|\*\/)/";

	public static function parseAnnotations($docComment) {}

}
