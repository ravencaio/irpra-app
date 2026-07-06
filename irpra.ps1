if ($args[0] -eq "-e") {
    $output = irpra_handler.exe $args[1]
} else {
    $output = irpra_handler.exe $args[0]
}

if ([string]::IsNullOrWhiteSpace($output)) {
    return
}

Set-Location $output

if ($args[0] -eq "-e") {
    explorer.exe $output
}