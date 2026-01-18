# Good practices to follow for helm charts

- Keep the name of the resources dynamic (using .Release.Name) to avoid collisions in busy clusters (if you want multiple releases in the same namespace)
- Do not include the namespace field in the templates. Helm automatically deploys the chart in the specified namespace unless overriden in the namespace field
- Keep the service ports configurable to avoid port collision in the namespace
- Separate the image name from the image tag to allow easier updation
- Use the sha256 function in annotations of a deployment using a configmap as env to reload the deployment incase of configmap update
