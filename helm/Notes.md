# Good practices to follow for helm charts

- Keep the name of the resources dynamic (using .Release.Name) to avoid collisions in busy clusters (if you want multiple releases in the same namespace)
- Do not include the namespace field in the templates. Helm automatically deploys the chart in the specified namespace unless overriden in the namespace field
- Keep the service ports configurable to avoid port collision in the namespace
- Separate the image name from the image tag to allow easier updation
- Use the sha256 function in annotations of a deployment using a configmap as env to reload the deployment incase of configmap update
- Use `helm show values [chart]` to get default values of a chart and direct the output to a file for configuration
- Use `helm get values [release name] -n [namespace name]` to get the values supplied by the user for the release
